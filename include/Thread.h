//! @file Thread.h
//! @author Matt Pillar
//!
//! This header file contains declarations for the Thread class.

#ifdef __cplusplus

#ifndef THREADMASTER_THREAD_H
#define THREADMASTER_THREAD_H

#include <pthread.h>

#include "Lock.h"
#include "Signal.h"

namespace ThreadMaster
{

//! @brief This class represents a thread.
//!
//! This class represents a thread and is used to simplify the starting and
//! stopping of threads in a program.
//!
//! Users should inherit from this class, define the required virtual functions,
//! and make use of the public methods of this class to start and stop their
//! threads.
class Thread
{
private:
    //! The pthread that we will use to start the main loop thread.
    pthread_t m_thread;

    //! Boolean indicating whether or not the user wants us to stop.
    volatile bool m_isStopped;

    //! Boolean indicating whether or not the thread is still running.
    volatile bool m_isRunning;

    //! Protection for the above private members.
    Lock m_lock;

    //! Common private member clear function. Used by the constructor and the
    //! Stop function.
    void Clear();

    //! Simple structure to hold some pointers for the DoRun phtread callback.
    struct ThreadParamHolder
    {
        Thread* thread;
        void* ptr;
    };

    //! To hold the params to the thread.
    ThreadParamHolder m_holder;

    //! Internal static function needed for the pthread library to wrap the run
    //! function.
    static void* DoRun(void* holder);

protected:
    //! Function called when the pthread has started. Derived classes must
    //! override this function.
    virtual void Run(void* ptr) = 0;

    //! Signal used for instant stopping. Instead of delaying, derived classes
    //! should use WaitSignal on this member.
    Signal m_signal;

public:
    //! Simple constructor. Initializes private members.
    Thread();

    //! Destructor. Stops the thread if it's running.
    ~Thread();

    //! Accessor indicating whether or not the thread has been told to stop.
    bool IsStopped() const;

    //! Accessor indicating whether or not the thread is still running.
    bool IsRunning() const;

    //! Creates and starts the pthread. Calls the Run function.
    //! @param ptr pointer to be passed to the Run function.
    void Start(void* ptr);

    //! Creates and starts the pthread. Calls the Run function.
    void Start();

    //! Stop the thread. Sets the stop variable, signals, and waits for the
    //! pthread.
    void Stop();

    //! Does not signal and does not set the stop variable. Simply waits for the
    //! pthread to exit naturally without poking it first.
    void StopWait();
};

} // namespace ThreadMaster

#endif
#endif // __cplusplus

