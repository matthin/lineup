#include "Compiler.h"

namespace lu {

Compiler::Compiler(const std::string& markdown) : html(toHTML(markdown)) {

}

std::string Compiler::toHTML(const std::string& markdown) const {
  if (markdown.at(0) == '#') {
    return "<h1>" + markdown.substr(1) + "</h1>";
  }
}

} // namespace lu

