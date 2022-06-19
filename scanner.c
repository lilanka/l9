#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c.h"
#include "scanner.h"

// setup the scanner
Scanner* init_scanner(const char* content) {
  Scanner* scanner = (Scanner*)malloc(sizeof(char*)*2 + sizeof(int)); 
  scanner->start = content;
  scanner->current = content;
  scanner->line = 1;
  return scanner;
}

// generate the desired token
static Token create_token(Scanner* scanner, TokenType type) {
  Token token;
  token.type = type;
  token.start = scanner->start;
  token.length = (int)(scanner->current - scanner->start);
  token.line = scanner->line;
  return token;
}

// error token
static Token error_token(Scanner* scanner, const char* message) {
  Token token;
  token.type = TERROR;
  token.start = message;
  token.length = (int)strlen(message);
  token.line = scanner->line;
  return token;
}

// scanner advances by one position
static char next(Scanner* scanner) {
  scanner->current++;
  return scanner->current[-1];
}

// scheck if scanner at the end of source code
static bool is_end(Scanner* scanner) {
  return *scanner->current == '\0';
}

// check if current char == given character
static bool is_it(Scanner* scanner, char c) {
  if (is_end(scanner)) 
    return false;
  if (scanner->current[1] != c) 
    return false;
  scanner->current++;
  return true;
}

// take current character which scanner is pointing at
static char current_char(Scanner* scanner) {
  return scanner->current[0];
}

// take next charcter of scanner pointing
static char proceeding_char(Scanner* scanner) {
  if (is_end(scanner)) return '\0';
  return scanner->current[1];
}

// avoid whitespaces
static void whitespaces(Scanner* scanner) {
  for (;;) {
    char c = current_char(scanner);
    switch (c) {
      case ' ': 
      case '\t': next(scanner); break;
      case '\n': scanner->line++; next(scanner); break;
      case '\v': scanner->line += 2; next(scanner); break;
      default: return;
    }
  }
}

// check commenting 
static bool is_comment(Scanner* scanner) {
  char c = current_char(scanner);
  if (c == '/') {
    while (current_char(scanner) != '\n' && !is_end(scanner)) 
      next(scanner);
    return true;
  } else if (c == '*') {
    while (!is_end(scanner)) {
      if (current_char(scanner) == '\n') 
        scanner->line++;
      if (current_char(scanner) == '*' && proceeding_char(scanner) == '/') {
        next(scanner);
        return true;
      }
      next(scanner);
    }    
  }
  return false;
}

// string tokens
static Token string(Scanner* scanner) {
  while (current_char(scanner) != '"' && !is_end(scanner)) {
    if (current_char(scanner) == '\n') 
      scanner->line++;
      next(scanner);
  }

  if (is_end(scanner)) 
    return error_token(scanner, "Undefined string.");

  next(scanner);
  return create_token(scanner, TSTRING);
}

static bool is_in_range(char a, char b, char c) {
  return a <= c && b >= c;
}

static bool is_digit(char c) {
  return c >= '0' && c <= '9';
}

static bool is_alphabetic(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

// numerical tokens
static Token number(Scanner* scanner) {
  while (is_digit(current_char(scanner)))
    next(scanner);

  if (current_char(scanner) == '.' && is_digit(proceeding_char(scanner))) {
    next(scanner);
    while (is_digit(current_char(scanner)))
      next(scanner);
  }
  return create_token(scanner, TNUMBER); 
}

static TokenType keyword(Scanner* scanner, int start, int length, const char* rest, TokenType type) {
  const int klength = KLENGTH(scanner);
  if (klength == start + length && memcmp(scanner->current + start, rest, length) == 0) {
    return type;
  } 
  return TID;
}

// identifier tokens
static Token id(Scanner* scanner) {
  while (is_alphabetic(current_char(scanner)) || is_digit(current_char(scanner)))
    next(scanner);

  const int klength = KLENGTH(scanner); 
  if (klength > KEYWORD_MAX_LENGTH || klength < KEYWORD_MIN_LENGTH)
    return create_token(scanner, TID);                            
  switch (scanner->start[0]) {
    case 'c': return create_token(scanner, keyword(scanner, 1, 3, "har", TCHAR));     
    case 'e': return create_token(scanner, keyword(scanner, 1, 3, "lse", TELSE));     
    case 'm': return create_token(scanner, keyword(scanner, 1, 3, "ain", TMAIN));     
    case 'n': return create_token(scanner, keyword(scanner, 1, 3, "ull", TNULL));     
    case 'p': return create_token(scanner, keyword(scanner, 1, 5, "rintf", TPRINT));     
    case 'r': return create_token(scanner, keyword(scanner, 1, 5, "eturn", TRETURN));     
    case 't': return create_token(scanner, keyword(scanner, 1, 3, "rue", TTRUE));     
    case 'v': return create_token(scanner, keyword(scanner, 1, 3, "oid", TVOID));     
    case 'w': return create_token(scanner, keyword(scanner, 1, 4, "hile", TWHILE));     
    case 'd': {
      if (klength > 1) {
        switch (scanner->start[1]) {
          case 'e': return create_token(scanner, keyword(scanner, 2, 4, "fine", TDEFINE));
          case 'o': return create_token(scanner, keyword(scanner, 2, 4, "uble", TDOUBLE));
        }
      }  
    }    
    case 'i': {
      if (klength > 1) {
        switch (scanner->start[1]) {
          case 'n': {
            switch (scanner->start[2]) {
              case 'c': return create_token(scanner, keyword(scanner, 3, 4, "lude", TINCLUDE));
              case 't': return create_token(scanner, keyword(scanner, 3, 0, "", TINT));
            }
          }
          case 'f': return create_token(scanner, keyword(scanner, 2, 0, "", TFOR));
        }
      }
    }
    case 'f': {
      if (klength > 1) {
        switch (scanner->start[1]) {
          case 'a': return create_token(scanner, keyword(scanner, 2, 3, "lse", TFALSE));
          case 'l': return create_token(scanner, keyword(scanner, 2, 3, "oat", TFLOAT));
          case 'o': return create_token(scanner, keyword(scanner, 2, 1, "r", TFOR));
        }
      }
    }
  }
}

Token tokenize(Scanner* scanner) {
  whitespaces(scanner);
  scanner->start = scanner->current;
  
  if (is_end(scanner)) 
    return create_token(scanner, TEOF);

  char c = next(scanner);
  if (is_digit(c)) 
    return number(scanner);
  if (is_alphabetic(c))
    return id(scanner);

  switch (c) {
    case '(': return create_token(scanner, TLPAREN);
    case ')': return create_token(scanner, TRPAREN);
    case '{': return create_token(scanner, TLBRACE);
    case '}': return create_token(scanner, TRBRACE);
    case ';': return create_token(scanner, TSEMICOLON); 
    case ',': return create_token(scanner, TCOMMA); 
    case '#': return create_token(scanner, THASH);
    case '/': 
      if (!is_comment(scanner)) { 
        return create_token(scanner, TFSLASH); 
      } else { 
        break; 
      }
    case '-': return create_token(scanner, TMINUS);
    case '+': return create_token(scanner, TPLUS);
    case '*': return create_token(scanner, TSTAR);
    case '!': return create_token(scanner, is_it(scanner, '=') ? TBANG_EQ : TBANG); 
    case '=': return create_token(scanner, is_it(scanner, '=') ? TEQ_EQ : TEQ); 
    case '>': return create_token(scanner, is_it(scanner, '=') ? TGREATER_EQ : TGREATER); 
    case '<': return create_token(scanner, is_it(scanner, '=') ? TLESS_EQ : TLESS); 
    case '&': return create_token(scanner, is_it(scanner, '&') ? TLESS_EQ : TLESS); 
    case '"': return string(scanner);
  }

  return error_token(scanner, "Undefined token type.");
}

