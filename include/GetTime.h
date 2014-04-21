//! @file GetTime.h
//! @author Matt Pillar
//!
//! This header file contains declarations for of time related functions in the
//! thread manager namespace.

#ifdef __cplusplus

#ifndef THREADMASTER_GETTIME_H
#define THREADMASTER_GETTIME_H

#include <string>
#include <stdint.h>

namespace ThreadMaster
{

//! A collection of static functions that return time information.
class GetTime
{
public:
    //! Return the current system time in milliseconds.
    static uint64_t Milli();

    //! Return the current system time in seconds.
    static time_t Secs();

    //! Return the current date in string format (%Y-%m-%d %H:M:%S).
    static std::string String();

    //! Return the current time in string format (%H:M:%S).
    static std::string ShortString();
};

} // namespace ThreadMaster

#endif
#endif // __cplusplus

