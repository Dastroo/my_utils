//
// Created by dawid on 08.04.2022.
//

#pragma once

#include <vector>
#include <sstream>
#include <cassert>
#include "ArgumentUtils.h"

namespace mutl {
    std::string to_lower(const std::string &str);

    std::string to_lower(char c);

    template<typename... S>
    std::string concatenate(S ... args) {
        std::stringstream ss;
        (ss << ... << std::forward<S>(args));
        return ss.str();
    }

    std::string format_with_comma(std::initializer_list<std::string> list);

    template<typename T>
    inline std::string format_with_comma(const std::vector<T> &v) {
        std::stringstream ss;
        ss << v[0];
        for (int tuple = 1; tuple < v.size(); ++tuple)
            ss << ", " << v[tuple];
        return ss.str();
    }

    /**
     *
     * @tparam i tuple parameter index
     * @param v dynamic array of tuples
     * @return comma seperated of given tuple parameter
     * @example
     *  std::vector\<std::tuple\<std::string, char, int>> v;\n
        v.emplace_back(std::tuple{"abc", 'a', 1});\n
        v.emplace_back(std::tuple{"def", 'b', 2});\n
        v.emplace_back(std::tuple{"ghi", 'c', 3});\n
        std::cout \<\< format_param_with_comma\<2>(v);\n
        <b>output:</b>
        "1, 2, 3"
    */
    template<size_t i, typename... Args>
    inline std::string format_param_with_comma(const std::vector<std::tuple<Args...>> &v) {
        std::stringstream ss;
        ss << std::get<i>(v[0]);
        for (int tuple = 1; tuple < v.size(); ++tuple)
            ss << ", " << std::get<i>(v[tuple]);
        return ss.str();
    }

/**
 *
 * @tparam i pair parameter index
 * @param v dynamic array of pairs
 * @return comma seperated string of given pair parameter
 * @example
 *  std::vector\<std::pair\<std::string, int>> v;\n
    v.emplace_back("abc", 1);\n
    v.emplace_back("def", 2);\n
    std::cout \<\< format_param_with_comma\<1>(v);\n
    <b>output:</b>
    "1, 2"
 */
    template<size_t i, typename... Args>
    inline std::string format_param_with_comma(const std::vector<std::pair<Args...>> &vector) {
        std::stringstream ss;
        ss << std::get<i>(vector[0]);
        for (int tuple = 1; tuple < vector.size(); ++tuple)
            ss << ", " << std::get<i>(vector[tuple]);
        return ss.str();
    }

    template<size_t begin, size_t ...indexes, typename Tuple>
    inline std::string format_with_comma(integer_pack<size_t, indexes...>, Tuple &&tuple) {
        std::stringstream ss;
        ss << std::get<begin>(tuple);
        ((ss << ", " << std::get<indexes>(tuple)), ...);

        return ss.str();
    }

    namespace {
        template<size_t begin, typename Tuple>
        inline std::string format_with_comma(Tuple &&tuple) {
            std::stringstream ss;
            ss << std::get<begin>(tuple);
            return ss.str();
        }
    }


    template<size_t begin, size_t end, typename... Args>
    inline std::string format_with_comma(Args ...args) {
        if (begin != end) {
            typename integer_range_generate<size_t, begin + 1, end, 1>::type indexes;
            return format_with_comma<begin>(indexes, std::forward_as_tuple(args...));
        } else
            return format_with_comma<begin>(std::forward_as_tuple(args...));
    }

    template<typename... Args>
    inline std::string format_with_comma(Args ...args) {
        constexpr int end = sizeof...(args) - 1;
        return format_with_comma<0, end>(args...);
    }

    template<size_t begin, size_t end>
    inline std::string format_with_comma(const std::string &s) {
        return s;
    }

    template<size_t begin, size_t end>
    inline std::string format_with_comma(const char *s) {
        return s;
    }

    template<size_t begin, size_t end>
    inline std::string format_with_comma(char c) {
        return std::string(1, c);
    }

    template<size_t begin, size_t end>
    inline std::string format_with_comma(int c) {
        return std::to_string(c);
    }

    std::string format_with_comma(const std::string &s);

    std::string format_with_comma(const char *s);

    std::string format_with_comma(char c);

    std::string format_with_comma(int c);
}




