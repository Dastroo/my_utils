//
// Created by dawid on 09.07.22.
//

#include "../include/Bit.h"

bool mutl::get(uint16_t bitset, uint16_t flag) {
  return (bitset & flag) > 0;
}

void mutl::set(uint16_t &bitset, uint16_t flag) {
  bitset |= flag;
}

void mutl::clear(uint16_t &bitset, uint16_t flag) {
  bitset &= ~flag;
}