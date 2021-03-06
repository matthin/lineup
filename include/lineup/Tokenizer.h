#pragma once

#include <string>
#include <vector>

#include "Token.h"

namespace lu {

class Tokenizer {
public:
  Tokenizer(const std::string& markdown);
  std::vector<Token> tokenize(const std::string& markdown) const;
  const std::vector<Token> tokens;

private:
  Operation detectType(const std::string& line) const;
  bool isOrderedList(const std::string& line) const;
};

} // namespace lu

