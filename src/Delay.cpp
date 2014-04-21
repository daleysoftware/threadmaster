//! @file Delay.cpp
//! @author Matt Pillar
//!
//! This file contains the implementation of some delay related functions in the
//! thread master namespace.

#include <sys/time.h>

#include "Delay.h"

namespace ThreadMaster
{

void Delay::Milli(uint64_t milli)
{
    usleep(milli * 1000);
}

} // namespace ThreadMaster

