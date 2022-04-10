//
// Created by dawid on 08.04.2022.
//

#include "../include/StringUtils.h"

std::string mutl::to_lower(const std::string &str) {
    std::string result;
    for (auto c: str)
        result += (char) std::tolower(c);
    return result;
}

std::string mutl::to_lower(char c) {
    // dont use bracers initializer there is a bug where that changes the outcome
    return std::string(1, (char) std::tolower(c));
}

std::string mutl::format_with_comma(const std::string &s) {
    return s;
}

std::string mutl::format_with_comma(const char *s) {
    return s;
}

std::string mutl::format_with_comma(char c) {
    return std::string(1, c);
}

std::string mutl::format_with_comma(int c) {
    return std::to_string(c);
}