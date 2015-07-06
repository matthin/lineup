#include "Parser.h"

#include "Compiler.h"
#include "Tokenizer.h"

namespace lu {

Parser::Parser(const std::string& markdown)
    : tokens(Tokenizer(markdown).tokens) {}

std::string Parser::toHTML() const {
  return Compiler(tokens).toHTML();
}

} // namespace lu

