#ifndef scanner_h
#define scanner_h

#define KEYWORD_MIN_LENGTH 2
#define KEYWORD_MAX_LENGTH 7

typedef enum {
  // single character
  TLPAREN, TRPAREN, 
  TLBRACE, TRBRACE,
  TCOMMA, TMINUS, TPLUS,
  TSEMICOLON, TFSLASH, 
  TBSLASH, TSTAR,

  // double character
  TBANG, TBANG_EQ,
  TEQ, TEQ_EQ,
  TGREATER, TGREATER_EQ,
  TLESS, TLESS_EQ,
  
  // literals
  TID, TSTRING, TNUMBER,

  // keywords
  TAND, TCHAR, TDOUBLE, TDEFINE,
  TELSE, TFALSE, TFLOAT, TFOR, TIF, 
  TINT, TINCLUDE, TMAIN, TNULL, TOR, 
  TPRINT, TRETURN, TTRUE, TSTATIC,
  TSTRUCT, TVOID, TWHILE,

  TERROR, TEOF
} TokenType;

typedef struct {
  const char* start;
  const char* current;
  int line;
} Scanner;

typedef struct {
  TokenType type;
  const char* start;
  int length;
  int line;
} Token;

Scanner* init_scanner();
Token tokenize(Scanner* scanner);

#endif
