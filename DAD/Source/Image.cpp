
/* Copyright (c) 2022 Nicolas Danet. */

/* < https://opensource.org/licenses/GPL-3.0 > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "Image.hpp"
#include "Time.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "exif.h"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

namespace core {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

Image::Image (const juce::File& f) : time_(), file_ (f)
{
    readEXIF (file_);
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

bool parseEXIF (easyexif::EXIFInfo& info, const juce::MemoryBlock& m)
{
    auto p = static_cast<const unsigned char*>(m.getData());
    auto s = static_cast<unsigned>(m.getSize());

    if (info.parseFrom (p, s)) { return false; }
    else {
        return true;
    }
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void Image::readEXIF (const juce::File& f)
{
    juce::MemoryBlock m;
    
    if (f.loadFileAsData (m) && m.getSize() > 0) {
    
        easyexif::EXIFInfo info;
        
        if (parseEXIF (info, m)) {
            time_ = Time::parse (info.DateTimeDigitized);
        }
    }
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
