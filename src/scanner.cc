#include <iostream>

#include "scanner.h"

namespace L9 {

inline bool Scanner::is_end() const {
  return *curr_ == '\0';
}

inline Token Scanner::tokanize(const TokenType type) const {
  Token token;
  token.type_ = type;
  token.start_ = start_;
  return token;
}

inline uchar Scanner::advance() {
  curr_++;
  return curr_[-1];
}

inline Token Scanner::invalid_token() const {
  Token token;
  token.type_ = TokenType::TINVALID;
  token.start_ = nullptr;
  return token;
}

inline uchar Scanner::next() const {
  return *curr_;
}

inline uchar Scanner::one_after_next() const {
  return *(curr_ + 1);
}

inline bool Scanner::is_character(const uchar c) const {
  return next() == c;
}

inline Token Scanner::single_line_comment() {
  while (next() != '\n' && !is_end()) 
    advance();
  return tokanize(TokenType::TCOMMENT);
}

inline Token Scanner::multi_line_comment() {
  while (next() != '-' && one_after_next() != '/') {
    if (next() == '\n')
      line_++;
    advance();
  } 
  curr_ += 2; 
  return tokanize(TokenType::TCOMMENT);
}

inline void Scanner::skip_whitespace() {
  while (true) {
    switch (next()) {
      case ' ':
      case '\r':
      case '\t': advance(); break;
      case '\n': advance(); line_++; break;
      default: return;
    } 
  }
}

inline bool Scanner::in_range(uchar c, uchar lower, uchar upper) const {
  return c >= lower && c <= upper;
} 

#define KEYWORDS(KEYWORD_GROUP, KEYWORD)  \
  KEYWORD_GROUP('a')                      \
  KEYWORD("and", TokenType::TAND)         \
  KEYWORD_GROUP('c')                      \
  KEYWORD("class", TokenType::TCLASS)     \
  KEYWORD_GROUP('e')                      \
  KEYWORD("else", TokenType::TELSE)       \
  KEYWORD_GROUP('f')                      \
  KEYWORD("false", TokenType::TFALSE)     \
  KEYWORD("for", TokenType::TFOR)         \
  KEYWORD("fn", TokenType::TFN)           \
  KEYWORD_GROUP('i')                      \
  KEYWORD("if", TokenType::TIF)           \
  KEYWORD_GROUP('n')                      \
  KEYWORD("none", TokenType::TNONE)       \
  KEYWORD_GROUP('o')                      \
  KEYWORD("or", TokenType::TOR)           \
  KEYWORD_GROUP('p')                      \
  KEYWORD("print", TokenType::TPRINT)     \
  KEYWORD_GROUP('r')                      \
  KEYWORD("return", TokenType::TRETURN)   \
  KEYWORD_GROUP('t')                      \
  KEYWORD("this", TokenType::TTHIS)       \
  KEYWORD("true", TokenType::TTRUE)       \
  KEYWORD_GROUP('w')                      \
  KEYWORD("while", TokenType::TWHILE) 

inline Token Scanner::identifier_or_keyword() {
  while (in_range(next(), 'a', 'z') || \
        in_range(next(), 'A', 'Z') || \
        in_range(next(), '1', '9'))
    advance();

  // change these valuses accordingly
  // when new keywords are implemented 
  const auto keyword_min_length = 2;
  const auto keyword_max_length = 6;

  const auto token_length = curr_ - start_;

  if (token_length < keyword_min_length ||  
      token_length > keyword_max_length)
    return tokanize(TokenType::TIDENTIFIER);

  switch (start_[0]) {
    default:
#define KEYWORD_GROUP_CASE(ch)        \
      break;                          \
    case ch:
#define KEYWORD(keyword, token_type)                                    \
  {                                                                     \
    const int keyword_length = sizeof(keyword) - 1;                     \
    if (token_length == keyword_length && start_[1] == keyword[1] &&    \
        (keyword_length <= 2 || start_[2] == keyword[2]) &&             \
        (keyword_length <= 3 || start_[3] == keyword[3]) &&             \
        (keyword_length <= 4 || start_[4] == keyword[4]) &&             \
        (keyword_length <= 5 || start_[5] == keyword[5]))               \
      return tokanize(token_type);                                      \
  }
      KEYWORDS(KEYWORD_GROUP_CASE, KEYWORD) 
  }
  return tokanize(TokenType::TIDENTIFIER);
#undef KEYWORDS
#undef KEYWORD
}

Token Scanner::scan() {
  skip_whitespace();
  start_ = curr_;    
  if (is_end()) 
    return tokanize(TokenType::TEOF);

  auto c = advance();

  if (in_range(c, 'a', 'z') || in_range(c, 'A', 'Z') || c == '_')
    return identifier_or_keyword();

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
      auto next_c = next();
      if (next_c == '/') {
        return single_line_comment();
      } else if (next_c == '-') {
        return multi_line_comment();
      } else { 
        return tokanize(TokenType::TSLASH);
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