//! This header file contains declarations for the Lock class.

#ifdef __cplusplus

#ifndef THREADMASTER_LOCK_H
#define THREADMASTER_LOCK_H

#include <pthread.h>

namespace ThreadMaster
{

//! @brief This class represents a lock, or a mutex.
//!
//! This class represents a lock and is used to simplify the use of mutexes
//! in a program.
class Lock
{
private:
    //! pthread mutex used for locking.
    pthread_mutex_t m_mutex;

public:
    //! Simple constructor. Initializes the pthread mutex.
    Lock();

    // Destroys the mutex.
    ~Lock();

    //! Take (acquire) the lock.
    void Take();

    //! Give (release) the lock.
    void Give();
};

}

#endif
#endif
