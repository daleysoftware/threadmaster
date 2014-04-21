//! @file Timer.h
//! @author Matt Pillar
//!
//! This header file contains declarations for the Timer class.

#ifdef __cplusplus

#ifndef THREADMASTER_TIMER_H
#define THREADMASTER_TIMER_H

#include "Thread.h"

namespace ThreadMaster
{

//! @brief This class represents a timer.
//!
//! This class represents a timer and is used to simplify the starting and
//! stopping of timers in a program.
//!
//! Users should inherit from this class and implement the required virtual
//! functions. The timer can then be started and stopped using the public API of
//! this class.
class Timer : public Thread
{
private:
    //! The current setting for the timer.
    unsigned int m_milli;

protected:
    //! Timer callback function that derived classes must override.
    virtual void Dispatch(void* ptr) = 0;

    //! Main loop from Thread.
    virtual void Run(void* ptr);

public:
    //! Constructor that sets the number of milliseconds to wait before the
    //! dispatch function is called.
    Timer(unsigned int milli);

    //! Get the number of milliseconds the timer is currently set to trigger on.
    unsigned int GetMilli() const {return m_milli;}

    //! Set the number of milliseconds the timer is currently set to trigger on.
    void SetMilli(unsigned int milli) {m_milli = milli;}
};

} // namespace ThreadMaster

#endif
#endif // __cplusplus

