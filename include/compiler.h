#pragma once

#include <memory>

#include "common.h"

namespace L9 {

class Compiler {
public:
  Compiler() {};
  // compile the source code
  void compile(const char* source);

};

}; // namespace L9