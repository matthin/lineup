#pragma once

#include <map>
#include <string>
#include <vector>

namespace lu {

enum struct Operation {
  H1,
  H2,
  H3,
  H4,
  H5,
  H6,
  OL,
  UL,
  P,
  Blank
};
const std::map<Operation, const char*> operationToText = {
  {Operation::H1, "h1"}, {Operation::H2, "h2"}, {Operation::H3, "h3"},
  {Operation::H4, "h4"}, {Operation::H5, "h5"}, {Operation::H6, "h6"},
  {Operation::OL, "ol"}, {Operation::UL, "ul"}, {Operation::P, "p"},
  {Operation::Blank, "blank"}
};
bool isOperationAList(const Operation operation);

class Token {
public:
  Token(Operation operation, const std::string& text);

  const Operation operation;
  const std::string text;
  // Needs to be a pointer to prevent endless recursion.
  // There were some issues with using unique_ptr, so I'm just leaving
  // it as a raw pointer for now.
  std::vector<Token>* childTokens = nullptr;

  bool operator ==(const Token& other) const {
    if (childTokens == nullptr) {
      return (operation == other.operation) && (text == other.text);
    } else {
      return (operation == other.operation) && (text == other.text) &&
             (*childTokens == *(other.childTokens));
    }
  }
  bool operator !=(const Token& other) const {
    return !(*this == other);
  };
};

inline std::ostream & operator <<(std::ostream& stream, const Token& token) {
  stream << std::string(
    operationToText.at(token.operation)
  ) << std::string(", ") << token.text;
  if (token.childTokens) {
    stream << std::string(" { ");
    for (const auto& childToken : *(token.childTokens)) {
      stream << childToken << std::string("; ");
    }
    stream << std::string("}");
  }
  return stream;
}

} // namespace lu

