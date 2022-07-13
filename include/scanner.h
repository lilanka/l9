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
  TokenType type_;
  const char* start_;
};

// scanner generates tokens
// - start: begining of the current token
// - curr: current character being looking at
// - line: line number of the current token
class Scanner {
public:
  Scanner(const char* source) noexcept : start_{source}, curr_{source} {};
  // scan source 
  Token scan();
  ~Scanner() = default;

private:
  // generate tokens
  inline Token tokanize(const TokenType type) const;

  inline bool is_end() const;
  inline Token invalid_token() const;
  inline bool is_character(const uchar c) const;

  // advance the current position by one
  inline uchar advance();
  // get next character without advancing
  inline uchar next() const;
  inline Token handle_comment();
  inline void skip_whitespace();

  const char* start_;
  const char* curr_;
  unsigned int line_ {1};
};

}; // namespace L9