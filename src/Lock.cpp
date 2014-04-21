//! @file Lock.cpp
//! @author Matt Pillar
//!
//! This file contains the implementation of the Lock class.

#include "Lock.h"

namespace ThreadMaster
{

Lock::Lock()
{
    pthread_mutex_init(&m_mutex, NULL);
}

Lock::~Lock()
{
    pthread_mutex_destroy(&m_mutex);
}

void Lock::Give()
{
    pthread_mutex_lock(&m_mutex);
}

void Lock::Take()
{
    pthread_mutex_unlock(&m_mutex);
}

} // namespace ThreadMaster

