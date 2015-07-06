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
      if (line.at(1) == '#') {
        if (line.at(2) == '#') {
          tokens.push_back(
            Token(Operation::H3, line.substr(3))
          );
        } else {
          tokens.push_back(
            Token(Operation::H2, line.substr(2))
          );
        }
      } else {
        tokens.push_back(
          Token(Operation::H1, line.substr(1))
        );
      }
    } else if (line.at(0) == '*') {
      tokens.push_back(
        Token(Operation::LI, line.substr(1))
      );
    }
  }

  return tokens;
}

} // namespace lu

