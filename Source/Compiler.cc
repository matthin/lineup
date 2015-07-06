#include "Compiler.h"

namespace lu {

Compiler::Compiler(const std::vector<Token> tokens)
    : tokens(tokens){

}

std::string Compiler::toHTML() const {
  std::string html;

  for (auto token : tokens) {
    switch (token.operation) {
    case Operation::H1:
      html += "<h1>" + token.text + "</h1>";
      break;
    case Operation::H2:
      html += "<h2>" + token.text + "</h2>";
      break;
    case Operation::H3:
      html += "<h3>" + token.text + "</h3>";
      break;
    default:
      // Should log a message saying the operation isn't supported yet.
      break;
    }
  }

  return html;
}

} // namespace lu

