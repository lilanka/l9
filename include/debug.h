#pragma once

#include "common.h"
#include "code.h"
#include "scanner.h"

namespace L9 {

class Debug {
public:
  Debug() {};
  // debug vm code
  void debug_vm_code(Code& code); 
  // debug token
  void debug_token(Token& token);
};

}; // namespace L9