//! This header file contains declarations for the AutoLock class.

#ifdef __cplusplus

#ifndef THREADMASTER_AUTOLOCK_H
#define THREADMASTER_AUTOLOCK_H

#include "Lock.h"

namespace ThreadMaster
{

//! @brief An AutoLock simplifies locking by giving and taking locks using scope
//!
//! This class can be used to scope a lock to simplify the giving and taking of
//! locks.
class AutoLock
{
private:
    //! Our own lock instance.
    Lock& m_lock;

public:
    //! Constructor takes the lock.
    AutoLock(Lock& lock) : m_lock(lock)
    {
        m_lock.Take();
    }

    //! Destructor gives the lock back.
    ~AutoLock()
    {
        m_lock.Give();
    }
};

}

#endif
#endif
