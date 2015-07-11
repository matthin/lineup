#include "Token.h"

namespace lu {

bool isOperationAList(const Operation operation) {
  return operation == Operation::OL || operation == Operation::UL;
}

Token::Token(const Operation operation, const std::string& text)
    : operation(operation), text(std::move(text)) {}

} // namespace lu

