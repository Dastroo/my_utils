//
// Created by dawid on 09.07.22.
//

#pragma once


#include <cstdint>
#include <bitset>

namespace mutl::bit {

    [[nodiscard]] bool
    has(uint16_t bitset, uint16_t flag);

    [[nodiscard]] bool
    has(uint32_t bitset, uint32_t flag);

    [[nodiscard]] bool
    has(uint64_t bitset, uint64_t flag);

    /// check if any bits from flag match with bitset
    [[nodiscard]] bool
    any(uint16_t bitset, uint16_t flag);

    /// check if any bits from flag match with bitset
    [[nodiscard]] bool
    any(uint32_t bitset, uint32_t flag);

    /// check if any bits from flag match with bitset
    [[nodiscard]] bool
    any(uint64_t bitset, uint64_t flag);

    /// sets true bits from flag to true in bitset
    void set(uint16_t &bitset, uint16_t flag);

    /// sets true bits from flag to true in bitset
    void set(uint32_t &bitset, uint32_t flag);

    /// sets true bits from flag to true in bitset
    void set(uint64_t &bitset, uint64_t flag);

    /**
     * @brief sets all bitset bits that match with those from flag to false
     * uint16_t bitset = 0b0000000000000111;
     * uint16_t flag1_ = 0b0000000000000001;
     * uint16_t flag2_ = 0b0000000000000010;
     * mutl::bit::clear(bitset, flag1_ | flag2_);
     * std::cout << bitset;
     * output: 0b0000000000000100
     */
    void clear(uint16_t &bitset, uint16_t flag);

    /**
     * @brief sets all bitset bits that match with those from flag to false
     * uint16_t bitset = 0b0000000000000111;
     * uint16_t flag1_ = 0b0000000000000001;
     * uint16_t flag2_ = 0b0000000000000010;
     * mutl::bit::clear(bitset, flag1_ | flag2_);
     * std::cout << bitset;
     * output: 0b0000000000000100
     */
    void clear(uint32_t &bitset, uint32_t flag);

    /**
     * @brief sets all bitset bits that match with those from flag to false
     * uint16_t bitset = 0b0000000000000111;
     * uint16_t flag1_ = 0b0000000000000001;
     * uint16_t flag2_ = 0b0000000000000010;
     * mutl::bit::clear(bitset, flag1_ | flag2_);
     * std::cout << bitset;
     * output: 0b0000000000000100
     */
    void clear(uint64_t &bitset, uint64_t flag);

}// namespace mutl::bit
