#ifndef ast_h
#define ast_h

#include "c.h"
#include "scanner.h"

typedef struct {
  Token current;    
  Token parent;
  bool error;     // if error token
} Node;

Node* generate_AST(Scanner* scanner);

#endif
