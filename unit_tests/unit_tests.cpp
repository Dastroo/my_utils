#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by dawid on 06.04.2022.
//

#include "../include/Bit.h"
#include "../include/StringUtils.h"
#include "../include/Time.h"
#include "doctest.h"
#include <fstream>
#include <bitset>

TEST_CASE("to_lower") {
    std::string s = "AbCD1";
    CHECK_EQ(mutl::to_lower('A'), "a");
    CHECK_EQ(mutl::to_lower(1), "\1");
    CHECK_EQ(mutl::to_lower("AB"), "ab");
    CHECK_EQ(mutl::to_lower("AbC"), "abc");
    CHECK_EQ(mutl::to_lower("abcd"), "abcd");
    CHECK_EQ(mutl::to_lower(s), "abcd1");
}

TEST_CASE(R"(format_param_with_comma)") {
    SUBCASE(R"(format_param_with_comma(const std::vector<T1, T2> &v))") {
        std::vector<std::pair<std::string, std::string>> v;
        v.emplace_back(std::make_pair("a", "b"));

        std::vector<std::pair<std::string, int>> v2;
        v2.emplace_back(std::make_pair("a", 1));
        v2.emplace_back(std::make_pair("b", 2));
        CHECK_EQ(mutl::format_param_with_comma<0>(v), "a");
        CHECK_EQ(mutl::format_param_with_comma<1>(v), "b");
        CHECK_EQ(mutl::format_param_with_comma<0>(v2), "a, b");
        CHECK_EQ(mutl::format_param_with_comma<1>(v2), "1, 2");
    }

    SUBCASE(R"(format_param_with_comma(const std::vector<std::tuple<Args...>> &v))") {
        std::vector<std::tuple<std::string>> vector;
        vector.emplace_back(std::tuple{"abc"});
        std::vector<std::tuple<std::string>> vector2;
        vector2.emplace_back(std::tuple{"a"});
        vector2.emplace_back(std::tuple{"b"});
        std::vector<std::tuple<std::string, int>> vector3;
        vector3.emplace_back(std::tuple{"a", 1});
        vector3.emplace_back(std::tuple{"b", 2});
        vector3.emplace_back(std::tuple{"c", 3});
        std::vector<std::tuple<char, int>> vector4;
        vector4.emplace_back(std::tuple{'a', 1});
        vector4.emplace_back(std::tuple{'b', 2});
        vector4.emplace_back(std::tuple{'c', 3});
        std::vector<std::tuple<std::string, char, int>> vector5;
        vector5.emplace_back(std::tuple{"abc", 'a', 1});
        vector5.emplace_back(std::tuple{"def", 'b', 2});
        vector5.emplace_back(std::tuple{"ghi", 'c', 3});
        CHECK_EQ(mutl::format_param_with_comma<0>(vector), "abc");
        CHECK_EQ(mutl::format_param_with_comma<0>(vector2), "a, b");
        CHECK_EQ(mutl::format_param_with_comma<1>(vector3), "1, 2, 3");
        CHECK_EQ(mutl::format_param_with_comma<0>(vector4), "a, b, c");
        CHECK_EQ(mutl::format_param_with_comma<2>(vector5), "1, 2, 3");
    }

    SUBCASE(R"(format_param_with_comma(const std::vector<Args...> &vector))") {
        std::vector<std::pair<std::string, std::string>> v;
        v.emplace_back("a", "egal");
        std::vector<std::pair<std::string, std::string>> v2;
        v2.emplace_back("abc", "egal");
        v2.emplace_back("def", "egal");
        std::vector<std::pair<char, char>> v3;
        v3.emplace_back('a', 'b');
        v3.emplace_back('c', 'd');
        std::vector<std::pair<std::string, int>> v4;
        v4.emplace_back("abc", 1);
        v4.emplace_back("def", 2);
        CHECK_EQ(mutl::format_param_with_comma<0>(v), "a");
        CHECK_EQ(mutl::format_param_with_comma<0>(v2), "abc, def");
        CHECK_EQ(mutl::format_param_with_comma<1>(v3), "b, d");
        CHECK_EQ(mutl::format_param_with_comma<0>(v4), "abc, def");
        CHECK_EQ(mutl::format_param_with_comma<1>(v4), "1, 2");
    }
}

TEST_CASE(R"(format_with_comma)") {
    SUBCASE(R"(format_with_comma(std::initializer_list<std::string> list))") {
        CHECK_EQ(mutl::format_with_comma({"a"}), "a");
        CHECK_EQ(mutl::format_with_comma({"a", "b"}), "a, b");
        CHECK_EQ(mutl::format_with_comma({"a", "b", "c"}), "a, b, c");
    }

    SUBCASE(R"(format_with_comma(const std::vector<T> &v))") {
        std::vector<std::string> v;
        v.emplace_back("abc");
        std::vector<std::string> v2;
        v2.emplace_back("abc");
        v2.emplace_back("def");
        v2.emplace_back("ghi");
        CHECK_EQ(mutl::format_with_comma(v), "abc");
        CHECK_EQ(mutl::format_with_comma(v2), "abc, def, ghi");
    }

    SUBCASE(R"(template<size_t begin, size_t end, typename... Args> format_with_comma(Args &&... args))") {
        std::string a = "a";
        CHECK_EQ(mutl::format_with_comma<0, 0>("a"), "a");
        CHECK_EQ(mutl::format_with_comma<0, 0>('a'), "a");
        CHECK_EQ(mutl::format_with_comma<0, 0>(1), "1");
        CHECK_EQ(mutl::format_with_comma<0, 0>(1), "1");
        CHECK_EQ(mutl::format_with_comma<0, 0>(a), "a");
        CHECK_EQ(mutl::format_with_comma<0, 1>("a", "b", "c", "d"), "a, b");
        CHECK_EQ(mutl::format_with_comma<2, 3>("a", "b", "c", "d"), "c, d");
        CHECK_EQ(mutl::format_with_comma<1, 2>("a", 'b', "c", "d"), "b, c");
        CHECK_EQ(mutl::format_with_comma<0, 0>(a, "b", 'c', "d"), "a");
    }

    SUBCASE(R"(format_with_comma(const S &&... args))") {
        std::string abc = "abc";
        SUBCASE(R"(format_with_comma(const std::string &s))") {
            CHECK_EQ(mutl::format_with_comma(abc), "abc");
        }
        SUBCASE(R"(format_with_comma(const char* s))") {
            CHECK_EQ(mutl::format_with_comma("a"), "a");
        }
        SUBCASE(R"(format_with_comma(char c))") {
            CHECK_EQ(mutl::format_with_comma('a'), "a");
        }

        SUBCASE(R"(format_with_comma(int c))") {
            CHECK_EQ(mutl::format_with_comma(1), "1");
        }

        CHECK_EQ(mutl::format_with_comma("a", "b"), "a, b");
        CHECK_EQ(mutl::format_with_comma(abc, abc), "abc, abc");
        CHECK_EQ(mutl::format_with_comma('a', "b"), "a, b");
        CHECK_EQ(mutl::format_with_comma(1, "b"), "1, b");
        CHECK_EQ(mutl::format_with_comma('a', "b", 1, abc), "a, b, 1, abc");
    }
}

TEST_CASE(R"(time)") {
    using namespace mutl::time;

    SUBCASE(R"(now<nanoseconds>())") {
        std::cout << now<nano>() << std::endl;
        std::cout << now<nanoseconds>() << std::endl;
    }

    SUBCASE(R"(now<seconds>())") {
        std::cout << now<sec>() << std::endl;
        std::cout << now<seconds>() << std::endl;
    }

    SUBCASE(R"(now<hours>())") {
        std::cout << now<h>() << std::endl;
        std::cout << now<hours>() << std::endl;
    }
}

TEST_CASE(R"(bit)") {
    using namespace mutl::bit;

    SUBCASE(R"(any(uint16_t bitset, uint16_t flag))") {
        const uint16_t bitset = 1 << 0;
        const uint16_t bitset1 = 1 << 1;
        const uint16_t bitset2 = 1 << 2;
        const uint16_t bitset3 = 1 << 3;

        const uint16_t flag = 1 << 0; // 0001
        const uint16_t flag1 = 1 << 1;// 0010
        const uint16_t flag2 = 1 << 2;// 0100
        const uint16_t flag3 = 1 << 3;// 1000

        CHECK_EQ(any(bitset, flag), true);
        CHECK_EQ(any(bitset, flag1), false);
        CHECK_EQ(any(bitset, flag2), false);
        CHECK_EQ(any(bitset, flag3), false);

        CHECK_EQ(any(bitset1, flag), false);
        CHECK_EQ(any(bitset1, flag1), true);
        CHECK_EQ(any(bitset1, flag2), false);
        CHECK_EQ(any(bitset1, flag3), false);

        CHECK_EQ(any(bitset2, flag), false);
        CHECK_EQ(any(bitset2, flag1), false);
        CHECK_EQ(any(bitset2, flag2), true);
        CHECK_EQ(any(bitset2, flag3), false);

        CHECK_EQ(any(bitset3, flag), false);
        CHECK_EQ(any(bitset3, flag1), false);
        CHECK_EQ(any(bitset3, flag2), false);
        CHECK_EQ(any(bitset3, flag3), true);
    }

    SUBCASE(R"(set(uint16_t &bitset, uint16_t flag))") {
        uint16_t bitset = 0;
        uint16_t bitset1 = 0;
        uint16_t bitset2 = 0;
        uint16_t bitset3 = 0;

        const uint16_t flag = 1 << 0; // 0001
        const uint16_t flag1 = 1 << 1;// 0010
        const uint16_t flag2 = 1 << 2;// 0100
        const uint16_t flag3 = 1 << 3;// 1000

        set(bitset, flag);
        CHECK_EQ(any(bitset, flag), true);
        CHECK_EQ(any(bitset, flag1), false);
        CHECK_EQ(any(bitset, flag2), false);
        CHECK_EQ(any(bitset, flag3), false);

        set(bitset1, flag1);
        CHECK_EQ(any(bitset1, flag), false);
        CHECK_EQ(any(bitset1, flag1), true);
        CHECK_EQ(any(bitset1, flag2), false);
        CHECK_EQ(any(bitset1, flag3), false);

        set(bitset2, flag2);
        CHECK_EQ(any(bitset2, flag), false);
        CHECK_EQ(any(bitset2, flag1), false);
        CHECK_EQ(any(bitset2, flag2), true);
        CHECK_EQ(any(bitset2, flag3), false);

        set(bitset3, flag3);
        CHECK_EQ(any(bitset3, flag), false);
        CHECK_EQ(any(bitset3, flag1), false);
        CHECK_EQ(any(bitset3, flag2), false);
        CHECK_EQ(any(bitset3, flag3), true);
    }

    SUBCASE(R"(clear(uint16_t &bitset, uint16_t flag))") {
        uint16_t bitset = 1 << 3; // 1000
        uint16_t bitset1 = 1 << 2;// 0100
        uint16_t bitset2 = 1 << 1;// 0010
        uint16_t bitset3 = 1 << 0;// 0001

        const uint16_t flag = 1 << 0; // 0001
        const uint16_t flag1 = 1 << 1;// 0010
        const uint16_t flag2 = 1 << 2;// 0100
        const uint16_t flag3 = 1 << 3;// 1000

        set(bitset, flag); // 1001
        clear(bitset, flag3); // 0001
        CHECK_EQ(any(bitset, flag), true);
        CHECK_EQ(any(bitset, flag1), false);
        CHECK_EQ(any(bitset, flag2), false);
        CHECK_EQ(any(bitset, flag3), false);

        set(bitset1, flag1); // 0110
        clear(bitset1, flag2);// 0010
        CHECK_EQ(any(bitset1, flag), false);
        CHECK_EQ(any(bitset1, flag1), true);
        CHECK_EQ(any(bitset1, flag2), false);
        CHECK_EQ(any(bitset1, flag3), false);

        set(bitset2, flag2); // 0110
        clear(bitset2, flag1);// 0100
        CHECK_EQ(any(bitset2, flag), false);
        CHECK_EQ(any(bitset2, flag1), false);
        CHECK_EQ(any(bitset2, flag2), true);
        CHECK_EQ(any(bitset2, flag3), false);

        set(bitset3, flag3); // 1001
        clear(bitset3, flag);// 1000
        CHECK_EQ(any(bitset3, flag), false);
        CHECK_EQ(any(bitset3, flag1), false);
        CHECK_EQ(any(bitset3, flag2), false);
        CHECK_EQ(any(bitset3, flag3), true);
    }
}

TEST_CASE(R"(contains)") {
    uint16_t bitset1 = 0b0000000000000111;
    uint16_t flag001 = 0b0000000000000001;
    uint16_t flag002 = 0b0000000000000010;

    uint16_t bitset2 = 0b0000000000000111;
    uint16_t flag003 = 0b0000000000001010;

    uint16_t bitset3 = 0b0000000000000011;


    CHECK_EQ(mutl::bit::has(bitset1, flag001 | flag002), true);
    CHECK_EQ(mutl::bit::has(bitset2, flag001 | flag003), false);
    CHECK_EQ(mutl::bit::has(bitset3, flag001 | flag002), true);
}

/*
TEST_CASE(R"()") {

}

SUBCASE(R"()") {

}
 */