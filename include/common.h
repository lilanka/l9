#pragma once

namespace L9 {

typedef unsigned char uchar;

#define INCRESE_CAPACITY(capacity)  \
  ((capacity) < 8 ? 8 : (capacity) * 2)

}; // namespace L9