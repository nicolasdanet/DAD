
/* Copyright (c) 2022 Nicolas Danet. */

/* < https://opensource.org/licenses/GPL-3.0 > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "Log.hpp"
#include "CSV.hpp"
#include "Time.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

namespace core {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

Log::Log (const juce::StringArray& a) : time_(), height_()
{
    jassert (a.size() == CSV::size());
    
    time_   = Time::parse (a[CSV::Item::datetime_local]);
    height_ = a[CSV::Item::altitude_m].getDoubleValue();
}

Log::Log (juce::Time t) : time_ (t), height_()
{

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
