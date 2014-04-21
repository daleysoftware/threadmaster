//! This file contains the implementation of the Timer class.

#include "Timer.h"

namespace ThreadMaster
{

Timer::Timer(unsigned int milli) : m_milli(milli)
{
    // Nothing to do.
}

void Timer::Run(void* ptr)
{
    while (!IsStopped())
    {
        m_signal.WaitSignal(m_milli);
        Dispatch(ptr);
    }
}

}
