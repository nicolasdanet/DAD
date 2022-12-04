
/* Copyright (c) 2022 Nicolas Danet. */

/* < https://opensource.org/licenses/GPL-3.0 > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "Sequence.hpp"
#include "CSV.hpp"
#include "Image.hpp"
#include "Log.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

namespace core {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

std::vector<juce::File> getChildWithExtension (const juce::File& directory, const juce::String& s)
{
    jassert (directory.isDirectory());
    
    std::vector<juce::File> t;

    for (const auto& i : juce::RangedDirectoryIterator (directory, false, s)) { t.push_back (i.getFile()); }
    
    return t;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

std::vector<Image> getSortedImages (const juce::File& directory)
{
    std::vector<Image> t;
    
    for (const auto& i : getChildWithExtension (directory, "*.JPG")) { t.emplace_back (i); }
    
    std::sort (t.begin(), t.end());
    
    return t;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void getLogsForFile (std::vector<Log>& v, const juce::File& f)
{
    juce::StringArray lines; f.readLines (lines);
    
    const int n = lines.size();
    
    if (n) {
    //
    if (lines[0] != CSV::header()) { return; }
    
    juce::StringArray t;
    
    for (int i = 1; i < n; ++i) {
    //
    t.clearQuick();
    t.addTokens (lines[i], ",", "");
    if (t.size() == CSV::size() && t[CSV::Item::istakingphoto].getIntValue()) {
        v.emplace_back (t);
    }
    //
    }
    //
    }
}

std::vector<Log> getSortedLogs (const juce::File& directory)
{
    std::vector<Log> t;
    
    for (const auto& i : getChildWithExtension (directory, "*.csv")) { getLogsForFile (t, i); }
    
    std::sort (t.begin(), t.end());
    
    return t;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

std::vector<Element> getElements (const juce::File& directory)
{
    std::vector<Log> logs (getSortedLogs (directory));
    
    std::vector<Element> t;
    
    if (logs.size()) {
    //
    for (const auto& i : getSortedImages (directory)) {
    //
    auto base = [&t]() -> std::optional<double>
    {
        if (t.empty()) { return {}; }
        else {
            return std::optional<double> (t.front().getHeight());
        }
    }();
    
    t.emplace_back (i, base, std::equal_range (std::cbegin (logs), std::cend (logs), Log (i.getTime())));
    //
    }
    //
    }

    return t;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

Sequence::Sequence (const juce::File& directory) : directory_ (directory), elements_ (getElements (directory))
{
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void Sequence::writeAsString (const juce::File& file)
{
    juce::StringArray a;
    
    for (auto& e : elements_) { a.add (e.asString()); }
    
    file.replaceWithText (a.joinIntoString (juce::newLine));
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void Sequence::write()
{
    if (elements_.size()) {
    //
    const juce::File f (directory_.getNonexistentChildFile ("Altitudes", ".txt", true));
    
    writeAsString (f);
    
    std::cout << "Dump: " << f.getFullPathName() << std::endl;
    //
    }
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
