//
// Created by dawid on 08.04.2022.
//

#pragma once

#include <cstdlib>
#include <unistd.h>

char* get_home_path() {
#if __linux__
    return getenv("HOME");
#endif
#if _WIN32
    return getenv("USERPROFILE");
#endif
}

bool is_linux() {
#if __linux__
    return true;
#else
    return false;
#endif
}

bool is_windows() {
#if _WIN32
    return true;
#else
    return false;
#endif
}

bool is_elevated() {
#if __linux__
    return !getuid();
#endif
#if _WIN32
    return // TODO: windows support
#endif
}
