#pragma once

#include "common.h"
#include "code.h"

namespace L9 {

class Debug {
public:
  Debug() {};
  // debug vm code
  void debug_vm_code(Code& code); 
};

}; // namespace L9