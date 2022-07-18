//
// Created by dawid on 09.07.22.
//

#include "../include/Bit.h"
#include <cstdint>

bool mutl::bit::has(uint16_t bitset, uint16_t flag) { return (bitset & flag) == flag; }
bool mutl::bit::has(uint32_t bitset, uint32_t flag) { return (bitset & flag) == flag; }
bool mutl::bit::has(uint64_t bitset, uint64_t flag) { return (bitset & flag) == flag; }

bool mutl::bit::any(uint16_t bitset, uint16_t flag) { return (bitset & flag) > 0; }
bool mutl::bit::any(uint32_t bitset, uint32_t flag) { return (bitset & flag) > 0; }
bool mutl::bit::any(uint64_t bitset, uint64_t flag) { return (bitset & flag) > 0; }

void mutl::bit::set(uint16_t &bitset, uint16_t flag) { bitset |= flag; }
void mutl::bit::set(uint32_t &bitset, uint32_t flag) { bitset |= flag; }
void mutl::bit::set(uint64_t &bitset, uint64_t flag) { bitset |= flag; }

void mutl::bit::clear(uint16_t &bitset, uint16_t flag) { bitset &= ~flag; }
void mutl::bit::clear(uint32_t &bitset, uint32_t flag) { bitset &= ~flag; }
void mutl::bit::clear(uint64_t &bitset, uint64_t flag) { bitset &= ~flag; }
