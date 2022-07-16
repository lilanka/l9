#pragma once 

#include <string>

#include "common.h"
#include "scanner.h"

namespace L9 {

// hand crafted parser based on pratt parsing technique
// - panic_ - when token are not valid, the compiler pases 
//            further but doesn't run the program. it compiles
//            on panic mode.
class Parser {
public:
  Parser(Scanner scanner) : scanner_{scanner} {}
  bool parse();
  void validate_token(TokenType type, std::string message);
  ~Parser() = default;

private:
  // throw error if current token is invalid
  void error(std::string message);

  Scanner scanner_;
  Token curr_;
  Token prev_;
  bool panic_{false};
};

}; // namespace L9