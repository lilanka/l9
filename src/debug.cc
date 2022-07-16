#include <iostream>

#include "debug.h"

namespace L9 {

/*
void Debug::debug_vm_code(Code& code) {
  for (int i = 0; i < code.code_count_; i++) {
    switch (code.code_[i]) {
      case OpType::ORETURN: std::cout << "ORETURN at line " << code.lines_[i] << std::endl; break;
      case OpType::OADD: std::cout << "OADD at line " << code.lines_[i] << std::endl; break;
      case OpType::OSUB: std::cout << "OSUB at line " << code.lines_[i] << std::endl; break;
      case OpType::OCONSTANT: std::cout << "OCONSTANT at line " << code.lines_[i] << std::endl; break;
    }
  }
}
*/

void Debug::debug_token(Token& token) {
  switch (token.type_) {
    case TokenType::TLBRACE: std::cout << "TLBRACE" << std::endl; break;
    case TokenType::TLPAREN: std::cout << "TLPAREN" << std::endl; break;
    case TokenType::TRPAREN: std::cout << "TRPAREN" << std::endl; break;
    case TokenType::TCOMMA: std::cout << "TCOMMA" << std::endl; break;
    case TokenType::TPLUS: std::cout << "TPLUS" << std::endl; break;
    case TokenType::TMINUS: std::cout << "TMINUS" << std::endl; break;
    case TokenType::TSLASH: std::cout << "TSLASH" << std::endl; break;
    case TokenType::TSTAR: std::cout << "TSTAR" << std::endl; break;
    case TokenType::TBANG: std::cout << "TBANG" << std::endl; break;
    case TokenType::TBANG_EQ: std::cout << "TBANG_EQ" << std::endl; break;
    case TokenType::TGREATER: std::cout << "TGREATER" << std::endl; break;
    case TokenType::TGREATER_EQ: std::cout << "TGREATER_EQ" << std::endl; break;
    case TokenType::TLESS: std::cout << "TLESS" << std::endl; break;
    case TokenType::TLESS_EQ: std::cout << "TLESS_EQ" << std::endl; break;
    case TokenType::TIDENTIFIER: std::cout << "TIDENTIFIER" << std::endl; break;
    case TokenType::TSTRING: std::cout << "TSTRING" << std::endl; break;
    case TokenType::TNUMBER: std::cout << "TNUMBER" << std::endl; break;
    case TokenType::TAND: std::cout << "TAND" << std::endl; break;
    case TokenType::TCLASS: std::cout << "TCLASS" << std::endl; break;
    case TokenType::TELSE: std::cout << "TELSE" << std::endl; break;
    case TokenType::TFALSE: std::cout << "TFALSE" << std::endl; break;
    case TokenType::TFOR: std::cout << "TFOR" << std::endl; break;
    case TokenType::TFN: std::cout << "TFN" << std::endl; break;
    case TokenType::TIF: std::cout << "TIF" << std::endl; break;
    case TokenType::TNONE: std::cout << "TNONE" << std::endl; break;
    case TokenType::TOR: std::cout << "TOR" << std::endl; break;
    case TokenType::TPRINT: std::cout << "TPRINT" << std::endl; break;
    case TokenType::TRETURN: std::cout << "TRETURN" << std::endl; break;
    case TokenType::TTHIS: std::cout << "TTHIS" << std::endl; break;
    case TokenType::TTRUE: std::cout << "TTRUE" << std::endl; break;
    case TokenType::TWHILE: std::cout << "TWHILE" << std::endl; break;
  }
}

}; // namespace L9