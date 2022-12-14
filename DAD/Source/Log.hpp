
/* Copyright (c) 2022 Nicolas Danet. */

/* < https://opensource.org/licenses/GPL-3.0 > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#pragma once

#include <JuceHeader.h>

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace core {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class Log {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    explicit Log (const juce::StringArray&);
    explicit Log (juce::Time);
    
    ~Log() = default;

public:
    Log (const Log&) = default;
    Log (Log&&) = default;
    Log& operator = (const Log&) = default;
    Log& operator = (Log&&) = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    juce::Time getTime() const
    {
        return time_;
    }
    
    double getHeight() const
    {
        return height_;
    }
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    bool operator < (const Log& o) const
    {
        return (time_ < o.time_);
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

private:
    juce::Time time_;
    double height_;
    
private:
    JUCE_LEAK_DETECTOR (Log)
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

