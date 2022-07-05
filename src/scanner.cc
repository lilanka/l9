#include <iostream>

#include "scanner.h"

namespace L9 {

inline bool Scanner::is_end() {
  return *curr == '\0';
}

inline Token Scanner::tokanize(TokenType type) {
  Token token;
  token.type = type;
  token.start = start;
  return token;
}

inline uchar Scanner::advance() {
  curr++;
  return curr[-1];
}

inline Token Scanner::invalid_token() {
  Token token;
  token.type = TokenType::TINVALID;
  token.start = nullptr;
  return token;
}

inline uchar Scanner::next() {
  return *curr;
}

inline bool Scanner::is_character(const uchar c) {
  return next() == c;
}

inline Token Scanner::handle_comment() { }

inline void Scanner::skip_whitespace() {
  while (true) {
    switch (next()) {
      case ' ':
      case '\r':
      case '\t': advance(); break;
      case '\n': advance(); line++; break;
      default: return;
    } 
  }
}

Token Scanner::scan() {
  skip_whitespace();
  start = curr;    
  if (is_end()) 
    return tokanize(TokenType::TEOF);
  char c = advance();

  switch (c) {
    case '(': return tokanize(TokenType::TLPAREN);
    case ')': return tokanize(TokenType::TRPAREN);
    case '{': return tokanize(TokenType::TLBRACE);
    case '}': return tokanize(TokenType::TRBRACE);
    case ',': return tokanize(TokenType::TCOMMA);
    case '+': return tokanize(TokenType::TPLUS);
    case '-': return tokanize(TokenType::TMINUS);
    case '*': return tokanize(TokenType::TSTAR);
    case '/': {
      if (next() != '/') {
        return tokanize(TokenType::TSLASH);
      } else {
        return handle_comment();
      }
    }
    case '!': return tokanize(is_character('=') ? TokenType::TBANG_EQ : TokenType::TBANG);
    case '=': return tokanize(is_character('=') ? TokenType::TEQ_EQ : TokenType::TEQ);
    case '<': return tokanize(is_character('=') ? TokenType::TLESS_EQ : TokenType::TLESS);
    case '>': return tokanize(is_character('=') ? TokenType::TGREATER_EQ: TokenType::TGREATER);
  }
  return invalid_token();
}

}; // namespace L9