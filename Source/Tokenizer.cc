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
    const auto type = detectType(line);
    std::string text;
    switch(type) {
    case Operation::H1:
      text = line.substr(1);
      break;
    case Operation::H2:
      text = line.substr(2);
      break;
    case Operation::H3:
      text = line.substr(3);
      break;
    case Operation::OL:
      text = line.substr(2);
      break;
    case Operation::UL:
      text = line.substr(1);
      break;
    case Operation::P:
      text = line;
      break;
    }

    tokens.push_back(Token(type, text));
  }

  return tokens;
}

Operation Tokenizer::detectType(const std::string& line) const {
  Operation type;

  if (line.at(0) == '#') {
    if (line.at(1) == '#') {
      if (line.at(2) == '#') {
        type = Operation::H3;
      } else {
        type = Operation::H2;
      }
    } else {
      type = Operation::H1;
    }
  } else if (
      // I need to automatically check if the char is numeric.
      (line.at(0) == '1' || line.at(0) == '2') && line.at(1) == '.'
  ) {
    type = Operation::OL;
  } else if (line.at(0) == '*') {
    type = Operation::UL;
  } else {
    type = Operation::P;
  }

  return type;
}

} // namespace lu

