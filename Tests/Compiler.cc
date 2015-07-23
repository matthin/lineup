#include "catch.hpp"
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

TEST_CASE("Compiles sub-lists") {
  lu::Token token(lu::Operation::OL, " Example one");
  token.childTokens = new std::vector<lu::Token>;
  token.childTokens->push_back(
    lu::Token(lu::Operation::OL, " Example two")
  );
  const lu::Compiler compiler(std::vector<lu::Token> {
    token
  });
  REQUIRE(
    compiler.toHTML() == "<ol><li> Example one<ol><li> Example two</li></ol>"
                         "</li></ol>"
  );
}

TEST_CASE("Compiles paragraphs") {
  const lu::Compiler compiler(std::vector<lu::Token> {
    lu::Token(lu::Operation::P, "First paragraph"),
    lu::Token(lu::Operation::P, "Second paragraph")
  });
  REQUIRE(
    compiler.toHTML() == "<p>First paragraph</p><p>Second paragraph</p>"
  );
}

