//! This file contains the implementation of the Signal class.

#include <time.h>
#include <sys/time.h>

#include "Signal.h"

namespace ThreadMaster
{

Signal::Signal()
{
    pthread_cond_init(&m_cond, NULL);

    pthread_mutex_init(&m_mutex, NULL);
    pthread_mutex_lock(&m_mutex);

    Clear();
}

Signal::~Signal()
{
    pthread_cond_destroy(&m_cond);
    pthread_mutex_destroy(&m_mutex);
}

void Signal::SendSignal()
{
    m_set = true;
    pthread_cond_signal(&m_cond);
}

void Signal::WaitSignal()
{
    WaitSignal(0);
}

void Signal::WaitSignal(unsigned int timeout)
{
    struct timeval current;
    gettimeofday(&current, NULL);

    struct timespec abstime;

    abstime.tv_sec = current.tv_sec + timeout / 1000;
    abstime.tv_nsec = current.tv_usec * 1000 + (timeout % 1000) * 1000;

    if (abstime.tv_nsec >= 1000000000)
    {
        abstime.tv_nsec %= 1000000000;
        abstime.tv_sec += 1;
    }

    if (m_set == false)
    {
        pthread_cond_timedwait(&m_cond, &m_mutex, &abstime);
        m_set = false;
    }
}

void Signal::Clear()
{
    m_set = false;
}

}
