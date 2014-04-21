//! @file Thread.cpp
//! @author Matt Pillar
//!
//! This file contains the implementation of the Thread class.

#include "Thread.h"
#include "Lock.h"
#include "AutoLock.h"

namespace ThreadMaster
{

Thread::Thread()
{
    m_holder.thread = this;
    Clear();
}

Thread::~Thread()
{
    Stop();
}

void* Thread::DoRun(void* holder)
{
    ThreadParamHolder* h = static_cast<ThreadParamHolder*>(holder);
    h->thread->Run(h->ptr);

    // Ensure that when the thread stops, the meta is cleared so we report that
    // we are no long running.
    h->thread->Clear();
}

void Thread::Clear()
{
    m_thread = 0;
    m_isStopped = false;
    m_isRunning = false;
}

bool Thread::IsStopped() const
{
    return m_isStopped;
}

bool Thread::IsRunning() const
{
    return m_isRunning;
}

void Thread::Start(void* ptr)
{
    AutoLock autoLock(m_lock);

    m_holder.ptr = ptr;
    m_isRunning = true;

    pthread_create(&m_thread, NULL, DoRun, &m_holder);
}

void Thread::Start()
{
    Start(NULL);
}

void Thread::Stop()
{
    AutoLock autoLock(m_lock);
 
    if (m_thread != 0)
    {
        m_isStopped = true;
        m_signal.SendSignal();
        pthread_join(m_thread, NULL);
    }

    Clear();
}

void Thread::StopWait()
{
    AutoLock autoLock(m_lock);

    if (m_thread != 0)
    {
        pthread_join(m_thread, NULL);
    }

    Clear();
}

} // namespace ThreadMaster

