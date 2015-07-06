#include "Token.h"

namespace lu {

Token::Token(const Operation operation, const std::string& text)
    : operation(operation), text(std::move(text)) {}

} // namespace lu

