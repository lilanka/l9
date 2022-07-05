#pragma once

#include "common.h"

namespace L9 {

enum class TokenType {
  // single-character
  TLPAREN, TRPAREN, TLBRACE, TRBRACE,
  TCOMMA, TMINUS, TPLUS, TSEMICOLON,
  TSLASH, TSTAR,
  // double-character
  TBANG, TBANG_EQ, TEQ, TEQ_EQ, 
  TGREATER, TGREATER_EQ, TLESS, TLESS_EQ,
  // literals
  TID, TSTRING, TNUMBER,
  // keywords
  TAND, TCLASS, TELSE, TFALSE, TFOR, TFN,
  TIF, TNONE, TOR, TPRINT, TRETURN, TTHIS,
  TTRUE, TWHILE, 

  TEOF, TINVALID
};

struct Token {
  TokenType type;
  const char* start;
};

// scanner generates tokens
// - start: begining of the current token
// - curr: current character being looking at
// - line: line number of the current token
class Scanner {
public:
  constexpr Scanner(const char* source): \
    start{source}, curr{source}, line{1} {};
  // scan source 
  Token scan();

private:
  // check end of source   
  inline bool is_end();
  // generate tokens
  inline Token tokanize(TokenType type);
  // invalid token
  inline Token invalid_token();
  // advance the current position by one
  inline uchar advance();
  // check if character is equal
  inline bool is_character(const uchar c);
  // get next character without advancing
  inline uchar next();
  // comments
  inline Token handle_comment();
  // skip whitespaces
  inline void skip_whitespace();

private:
  const char* start;
  const char* curr;
  unsigned int line;
};

}; // namespace L9