#include <iostream>

#include "code.h"

namespace L9 {

int Code::pool_write(Value value) {
  if (pool_count + 1 > pool_capacity) {
    pool_capacity = INCRESE_CAPACITY(pool_capacity);
    const_pool.reserve(pool_capacity);
  }
  const_pool[pool_count] = value;
  pool_count++;
  return pool_count - 1;
}

void Code::code_write(uchar byte, int line) {
  if (code_count + 1 > code_capacity) {
    code_capacity = INCRESE_CAPACITY(code_capacity);
    code.reserve(code_capacity);
    lines.reserve(code_capacity);
  }
  code[code_count] = byte;
  lines[code_count] = line;
  code_count++;
}

}; // namespace L9