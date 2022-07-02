#pragma once

namespace L9 {

// scanner generates tokens
// - start: begining of the current token
// - curr: current character being looking at
// - line: line number of the current token
class Scanner {
public:
  constexpr Scanner(const char* source): \
    start{source}, curr{source}, line{1} {};

private:
  const char* start;
  const char* curr;
  int line;
};

}; // namespace L9