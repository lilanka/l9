#include <iostream>

#include "compiler.h"
#include "scanner.h"
#include "debug.h"

namespace L9 {

void Compiler::compile(const char* source) const {
  Scanner scanner{source};

  auto line = -1;
  while (true) {
    Token token = scanner.scan();  

#define DEBGUG_TRACING
#ifdef DEBGUG_TRACING
    Debug debug;
    debug.debug_token(token);
#endif

    if (token.type_ == TokenType::TEOF)
      break;
  }
}

}; // namespace L9