#pragma once

#include <map>
#include <string>

namespace lu {

enum struct Operation {
  H1,
  H2,
  H3,
  LI
};
const std::map<Operation, const char*> operationToText = {
  {Operation::H1, "H1"}, {Operation::H2, "H3"}, {Operation::H3, "H3"},
  {Operation::LI, "LI"}
};

class Token {
public:
  Token(Operation operation, const std::string& text);

  const Operation operation;
  const std::string text;

  bool operator ==(const Token& other) const {
    return (operation == other.operation) && (text == other.text);
  }
  bool operator !=(const Token& other) const {
    return !(*this == other);
  };
};

inline std::ostream & operator <<(std::ostream& stream, const Token& token) {
  stream << std::string(
    operationToText.at(token.operation)
  ) << std::string(", ") << token.text;
  return stream;
}

} // namespace lu

