#include "Catch.h"
#include "Compiler.h"

TEST_CASE("Compiles headers") {
  const lu::Compiler compiler(std::vector<lu::Token> {
    {lu::Token(lu::Operation::H1, " Hello")},
    {lu::Token(lu::Operation::H2, " Hello")},
    {lu::Token(lu::Operation::H3, " Hello")}
  });
  REQUIRE(
    compiler.toHTML() == "<h1> Hello</h1><h2> Hello</h2><h3> Hello</h3>"
  );
}

