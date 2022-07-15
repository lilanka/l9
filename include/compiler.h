#pragma once

#include <memory>

#include "common.h"
#include "code.h"

namespace L9 {

class Compiler {
public:
  Compiler() {};
  // compile the source code
  bool compile(const char* source, Code& code) const;
  ~Compiler() = default;
};

}; // namespace L9