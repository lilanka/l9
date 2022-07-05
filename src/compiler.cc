#include <iostream>

#include "compiler.h"
#include "scanner.h"
#include "debug.h"

namespace L9 {

void Compiler::compile(const char* source) {
  Scanner scanner{source};

  int line = -1;
  while (true) {
    Token token = scanner.scan();  

#define DEBGUG_TRACING
#ifdef DEBGUG_TRACING
    Debug debug;
    debug.debug_token(token);
#endif
  }
}

}; // namespace L9