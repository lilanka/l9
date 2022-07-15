#include <iostream>

#include "parser.h"
#include "scanner.h"

namespace L9 {

void Parser::error(Token& token, std::string message) const {
  std::cout << "Error at line " << token.line_ << " position " << token.start_ << std::endl;
}

bool Parser::parse() {
  prev_ = curr_;
  
  while (true) {
    curr_ = scanner_.scan();
    
    if (curr_.type_ != TokenType::TINVALID) 
      break;
    
    error(curr_, "Invalid token");
  }
  std::cout << "passed "  << std::endl;
  return true;
}

}; // namespace L9