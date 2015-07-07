#include "Catch.hpp"
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

TEST_CASE("Compiles lists") {
  const lu::Compiler compiler(std::vector<lu::Token> {
    {lu::Token(lu::Operation::OL, " Example one")},
    {lu::Token(lu::Operation::OL, " Example two")},
    {lu::Token(lu::Operation::OL, " Example three")},
    {lu::Token(lu::Operation::UL, " Example four")},
    {lu::Token(lu::Operation::UL, " Example five")}
  });
  REQUIRE(
    compiler.toHTML() == "<ol><li> Example one</li><li> Example two</li>"
                         "<li> Example three</li></ol><ul>"
                         "<li> Example four</li><li> Example five</li></ul>"
  );
}

