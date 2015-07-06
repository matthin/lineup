#include "Catch.h"
#include "Compiler.h"

TEST_CASE("Compiles to html") {
  const lu::Compiler compiler(std::vector<lu::Token> {
    {lu::Token(lu::Operation::H1, " Hello")}
  });
  REQUIRE(compiler.toHTML() == "<h1> Hello</h1>");
}

