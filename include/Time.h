//
// Created by dawid on 5/15/22.
//

#pragma once

#include <chrono>

namespace mutl::time {

    typedef std::chrono::nanoseconds nanoseconds;
    typedef std::chrono::nanoseconds nano;
    typedef std::chrono::microseconds microseconds;
    typedef std::chrono::microseconds micro;
    typedef std::chrono::milliseconds milliseconds;
    typedef std::chrono::milliseconds milli;
    typedef std::chrono::seconds seconds;
    typedef std::chrono::seconds sec;
    typedef std::chrono::minutes minutes;
    typedef std::chrono::minutes min;
    typedef std::chrono::hours hours;
    typedef std::chrono::hours h;

    /**
     * get current time since epoch (1970) in your desired unit of time
     * @tparam T hours | minutes | seconds | microseconds | milliseconds | nanoseconds
     * @return unsigned long int | uint64_t units_of_time since epoch
     * @example
     * using namespace mutl::time;\n
     * now\<sec>();
     */
    template<typename T>
    static uint64_t now() {
        using namespace std::chrono;
        return time_point_cast<T>(system_clock::now()).time_since_epoch().count();
    }

} // mutl::time