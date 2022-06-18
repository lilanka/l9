#include <stdio.h>

#include "c.h"
#include "compiler.h"
#include "scanner.h"
#include "debug.h"

void compile(const char* content) {
  Scanner* scanner = init_scanner(content);  

  int line = -1;
  for (;;) {
    Token token = tokenize(scanner);
    if (token.line != line)
      line = token.line;
    //printf("%2d, %i, %s\n", token.type, token.length, token.start);
   
    debug_tokens(token);

    if (token.type == TEOF) break;
  }
}
