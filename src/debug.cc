#include "debug.h"

namespace L9 {

void Debug::debug_vm_code(Code& code) {
  for (int i = 0; i < code_count; i++) {
    switch (code.code[i]) {
      case OP_RETURN: std::cout << "OP_RETURN at " << i + 1 << std::endl; break;
      case OP_ADD: std::cout << "OP_ADD at " << i + 1 << std::endl; break;
      case OP_CONSTANT: std::cout << "OP_CONSTANT at " << i + 1 << std::endl; break;
    }
  }
}

}; // namespace L9