#include "Compiler.h"

namespace lu {

Compiler::Compiler(const std::vector<Token> tokens)
    : tokens(tokens){

}

std::string Compiler::toHTML() const {
  std::string html;

  for (auto token : tokens) {
    if (token.operation == Operation::H1) {
      html += "<h1>" + token.text + "</h1>";
    }
  }

  return html;
}

} // namespace lu

