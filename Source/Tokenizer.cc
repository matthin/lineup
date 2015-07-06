#include "Tokenizer.h"

#include <sstream>

namespace lu {

Tokenizer::Tokenizer(const std::string& markdown)
    : tokens(tokenize(markdown)) {

}

std::vector<Token> Tokenizer::tokenize(const std::string& markdown) const {
  std::vector<Token> tokens;

  std::istringstream stream(markdown);
  std::string line;
  while (std::getline(stream, line)) {
    if (line.at(0) == '#') {
      tokens.push_back(
        Token(Operation::H1, line.substr(1))
      );
    }
  }

  return tokens;
}

} // namespace lu

