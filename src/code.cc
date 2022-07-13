#include <iostream>

#include "code.h"

namespace L9 {

int Code::pool_write(const Value value) {
  if (pool_count_ + 1 > pool_capacity_) {
    pool_capacity_ = INCRESE_CAPACITY(pool_capacity_);
    const_pool_.reserve(pool_capacity_);
  }
  const_pool_[pool_count_] = value;
  pool_count_++;
  return pool_count_ - 1;
}

void Code::code_write(const uchar byte, const int line) {
  if (code_count_ + 1 > code_capacity_) {
    code_capacity_ = INCRESE_CAPACITY(code_capacity_);
    code_.reserve(code_capacity_);
    lines_.reserve(code_capacity_);
  }
  code_[code_count_] = byte;
  lines_[code_count_] = line;
  code_count_++;
}

}; // namespace L9