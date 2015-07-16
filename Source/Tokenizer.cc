#include "Tokenizer.h"

#include <cctype>
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
    case Operation::H4:
      text = line.substr(4);
      break;
    case Operation::H5:
      text = line.substr(5);
      break;
    case Operation::H6:
      text = line.substr(6);
      break;
    case Operation::OL:
      text = line.substr(line.find('.') + 1);
      break;
    case Operation::UL:
      text = line.substr(1);
      break;
    case Operation::P:
      text = line;
      break;
    case Operation::Blank:
      text = "";
      break;
    }

    if (tokens.size() > 0) {
      auto& prevToken = tokens.back();
      if (type == Operation::P && prevToken.operation == Operation::P) {
        text = prevToken.text + text;
        tokens.pop_back();
      } else if (
        isOperationAList(type) && isOperationAList(prevToken.operation)
      ) {
        if (line.substr(0, 4) == "    ") {

          if (!prevToken.childTokens) {
            prevToken.childTokens = new std::vector<Token>;
          }
          prevToken.childTokens->push_back(
            Token(Operation::OL, text)
          );
          continue;
        }
      }
    }

    tokens.push_back(Token(type, text));
  }

  return tokens;
}

Operation Tokenizer::detectType(const std::string& line) const {
  Operation type;

  if (line.empty()) {
    type = Operation::Blank;
  } else if (line.at(0) == '#') {
    if (line.at(1) == '#') {
      if (line.at(2) == '#') {
        if (line.at(3) == '#') {
          if (line.at(4) == '#') {
            if (line.at(5) == '#') {
              type = Operation::H6;
            } else {
              type = Operation::H5;
            }
          } else {
            type = Operation::H4;
          }
        } else {
          type = Operation::H3;
        }
      } else {
        type = Operation::H2;
      }
    } else {
      type = Operation::H1;
    }
  } else if (isOrderedList(line)) {
    type = Operation::OL;
  } else if (line.at(0) == '*') {
    type = Operation::UL;
  } else {
    type = Operation::P;
  }

  return type;
}

bool Tokenizer::isOrderedList(const std::string& line) const {
  if (!std::isdigit(line.at(0)) && line.at(0) != ' ') {
    return false;
  }

  bool prevIsDigit = false;
  for (const auto character : line) {
    if (std::isdigit(character)) {
      prevIsDigit = true;
    } else if (prevIsDigit && character == '.') {
      return true;
    }
  }

  return false;
}

} // namespace lu

