#include <iostream>

#include "compiler.h"
#include "scanner.h"
#include "vm.h"
#include "parser.h"

namespace L9 {

bool Compiler::compile(const char* source, Code& code) const {
  Scanner scanner{source};
  Parser parser(scanner);
  auto parsed = parser.parse();
  return parsed;
}

}; // namespace L9