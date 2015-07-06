#include <vector>

#include "Catch.h"
#include "Token.h"
#include "Tokenizer.h"

TEST_CASE("Tokenizes a h1") {
  const lu::Tokenizer tokenizer("# Hello");
  REQUIRE(
    tokenizer.tokens == std::vector<lu::Token> {
      {lu::Token(lu::Operation::H1, " Hello")}
    }
  );
}

TEST_CASE("Tokenizes a h2") {
  const lu::Tokenizer tokenizer("## Hello");
  REQUIRE(
    tokenizer.tokens == std::vector<lu::Token> {
      {lu::Token(lu::Operation::H2, " Hello")}
    }
  );
}

TEST_CASE("Tokenizes a h3") {
  const lu::Tokenizer tokenizer("### Hello");
  REQUIRE(
    tokenizer.tokens == std::vector<lu::Token> {
      {lu::Token(lu::Operation::H3, " Hello")}
    }
  );
}

TEST_CASE("Tokenizes lists") {
  const lu::Tokenizer tokenizer(
    "* Example one\n"
    "* Example two"
  );
  // Can't directly pass in vector literal with multiple elements.
  const auto tokens = std::vector<lu::Token> {
    {lu::Token(lu::Operation::LI, " Example one")},
    {lu::Token(lu::Operation::LI, " Example two")}
  };
  REQUIRE(
    tokenizer.tokens == tokens
  );
}

