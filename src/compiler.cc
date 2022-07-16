#include <iostream>

#include "compiler.h"
#include "scanner.h"
#include "vm.h"
#include "parser.h"
#include "codegen.h"

namespace L9 {

bool Compiler::compile(const char* source, Code& code) const {
  Scanner scanner{source};
  Parser parser{scanner};
  CodeGen codegen{code};
  auto parsed = parser.parse();
  if (parsed) 
    //codegen.generate_bytecode();
    return true;
  codegen.end();
  return parsed;
}

}; // namespace L9