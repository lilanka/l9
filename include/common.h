#pragma once

#include <cstdint>

namespace L9 {

typedef unsigned char uchar;
typedef uint8_t ui8;

#define INCRESE_CAPACITY(capacity)  \
  ((capacity) < 8 ? 8 : (capacity) * 2)

}; // namespace L9