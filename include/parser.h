#pragma once 

#include <string>

#include "scanner.h"

namespace L9 {

// hand crafted parser based on pratt parsing technique
class Parser {
public:
  Parser(Scanner scanner) : scanner_{scanner} {}
  bool parse();
  ~Parser() = default;

private:
  void error(Token& token, std::string message) const;

  Scanner scanner_;
  Token curr_;
  Token prev_;
};

}; // namespace L9