#pragma once

#include <vector>

#include "Token.h"

namespace lu {

class Compiler {
public:
  Compiler(const std::vector<Token> tokens);
  std::string toHTML() const;

private:
  const std::vector<Token> tokens;
  int compileList(
    std::string* html, const Token& token, Operation listType
  ) const;
};

} // namespace lu

