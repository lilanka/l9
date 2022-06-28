#include <iostream>

#include "code.h"

namespace L9 {

#define INCRESE_CAPACITY(capacity)  \
  ((capacity) < 8 ? 8 : (capacity) * 2)

int Code::pool_write(Value value) {
  if (pool_count + 1 > pool_capacity) {
    pool_capacity = INCRESE_CAPACITY(pool_capacity);
    const_pool.reserve(pool_capacity);
  }
  const_pool[pool_count] = value;
  pool_count++;
  return pool_count - 1;
}

void Code::code_write(uchar byte) {
  if (code_count + 1 > code_capacity) {
    code_capacity = INCRESE_CAPACITY(code_capacity);
    code.reserve(code_capacity);
  }
  code[code_count] = byte;
  code_count++;
}

void Code::_D_code_print() {
  for (int i = 0; i < code_count; i++) {
    if (code[i] == OP_RETURN) {
      std::cout << "OP_RETURN at " << i + 1 << std::endl;
    } else if (code[i] == OP_ADD) {
      std::cout << "OP_ADD at " << i + 1 << std::endl;
    } else if (code[i] == OP_CONSTANT) {
      std::cout << "OP_CONSTANT at " << i + 1 << std::endl;
    }
  }
}
}; // namespace L9