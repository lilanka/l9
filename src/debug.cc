#include <iostream>

#include "debug.h"

namespace L9 {

void Debug::debug_vm_code(Code& code) {
  for (int i = 0; i < code.code_count_; i++) {
    switch (code.code_[i]) {
      case OP_RETURN: std::cout << "OP_RETURN at line " << code.lines_[i] << std::endl; break;
      case OP_ADD: std::cout << "OP_ADD at line " << code.lines_[i] << std::endl; break;
      case OP_SUB: std::cout << "OP_SUB at line " << code.lines_[i] << std::endl; break;
      case OP_CONSTANT: std::cout << "OP_CONSTANT at line " << code.lines_[i] << std::endl; break;
    }
  }
}

void Debug::debug_token(Token& token) {
  switch (token.type_) {
    case TokenType::TLBRACE: std::cout << "TLBRACE" << std::endl; break;
  }
}

}; // namespace L9