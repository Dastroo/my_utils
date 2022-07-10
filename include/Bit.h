//
// Created by dawid on 09.07.22.
//

#pragma once


#include <cstdint>


namespace mutl {

[[nodiscard]] static bool get(uint16_t bitset, uint16_t flag);

static void set(uint16_t &bitset, uint16_t flag);

static void clear(uint16_t &bitset, uint16_t flag);

}; // namespace Bit
