#include <stdio.h>
#include <stdlib.h>

#include "c.h"
#include "compiler.h"
#include "scanner.h"
#include "debug.h"
#include "ast.h"

// if a node of AST is token TERROR
static void handle_error_token(Node* node, const char* message) {
  fprintf(stderr, "Error at line %i", node->current.line);
  fprintf(stderr, "%s\n", message);
  node->error = true;
}

// generate AST 
static void gen_AST(Scanner* scanner, Node* node) {
  node->parent = node->current;

  for (;;) {
    node->current = tokenize(scanner);
    if (node->current.type != TERROR) 
      break;
     
    handle_error_token(node, "Error token detected");
    printf("%s\n", "passed");
  }
}

bool compile(const char* content) {
  Scanner* scanner = init_scanner(content);  
  Node node;
  gen_AST(scanner, &node);

  /*
  expression();
  consume(TEOF, "Expect end of expression");
  */
  return !node.error;
}
