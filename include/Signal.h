#ifndef THREADMASTER_SIGNAL_H
#define THREADMASTER_SIGNAL_H

#include <pthread.h>

namespace ThreadMaster
{

//! @brief This class represents a signal.
//!
//! This class represents a signal and is used to simplify the use of pthread
//! conditionals.
class Signal
{
private:
    //! The pthread conditional that we will be manipulating.
    pthread_cond_t m_cond;

    //! The mutex required to call pthread conditional wait.
    pthread_mutex_t m_mutex;

    //! Boolean indicating whether or not the object has been signaled.
    volatile bool m_set;

protected:

public:
    //! Simple constructor. Clears the signal object and initializes the signal
    //! conditional.
    Signal();

    //! Destroy the signal.
    ~Signal();

    //! Send a signal.
    void SendSignal();

    //! Wait for a signal indefinitely.
    void WaitSignal();

    //! Wait for a signal for a maximum of timeout milliseconds.
    //! @param timeout maximum time to wait in milliseconds.
    void WaitSignal(unsigned int timeout);

    //! Clear the set flag (set it so false) so that we don't think we have been
    //! signalled.
    void Clear();
};

}

#endif
