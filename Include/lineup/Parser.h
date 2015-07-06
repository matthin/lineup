#pragma once

#include <string>
#include <vector>

#include "Token.h"

namespace lu {

class Parser {
public:
  Parser(const std::string& markdown);
  std::string toHTML() const;

private:
  std::vector<Token> tokens;
};

} // namespace lu

