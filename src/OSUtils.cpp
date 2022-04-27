//
// Created by dawid on 18.04.22.
//

#include <cstdlib>
#include <unistd.h>
#include "../include/OSUtils.h"

char *mutl::get_home_path() {
#if __linux__
    return getenv("HOME");
#endif
#if _WIN32
    return getenv("USERPROFILE");
#endif
}

bool mutl::is_linux() {
#if __linux__
    return true;
#else
    return false;
#endif
}

bool mutl::is_windows() {
#if _WIN32
    return true;
#else
    return false;
#endif
}

bool mutl::is_elevated() {
#if __linux__
    return !getuid();
#endif
#if _WIN32
    return // TODO: windows support
#endif
}