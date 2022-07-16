#include <iostream>

#include "parser.h"
#include "scanner.h"

namespace L9 {

void Parser::error(std::string message) {
  if (panic_)
    return;
  panic_ = true;
  std::cout << "Error at line " << curr_.line_ << " position " << curr_.start_ << std::endl;
}

void Parser::validate_token(TokenType type, std::string message) {
  if (curr_.type_ == type) {
    parse();
    return;
  }
  error(message);
}

bool Parser::parse() {
  prev_ = curr_;
  
  while (true) {
    curr_ = scanner_.scan();
    
    if (curr_.type_ != TokenType::TINVALID) 
      break;
    
    error("Invalid token");
  }
  std::cout << "passed "  << std::endl;
  return true;
}

}; // namespace L9