#ifndef THREADMASTER_DELAY_H
#define THREADMASTER_DELAY_H

#include <stdint.h>
#include <unistd.h>
#include <pthread.h>

namespace ThreadMaster
{

//! A collection of static functions related to delaying thread execution.
class Delay
{
public:
    //! Delay thread execution for milli milliseconds.
    //! @param milli the number of milliseconds to delay the thread.
    static void Milli(uint64_t milli);
};

}

#endif
