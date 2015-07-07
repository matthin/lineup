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
    "* Example two\n"
    "1. Example three\n"
    "2. Example four"
  );
  // Can't directly pass in vector literal with multiple elements.
  const auto tokens = std::vector<lu::Token> {
    {lu::Token(lu::Operation::UL, " Example one")},
    {lu::Token(lu::Operation::UL, " Example two")},
    {lu::Token(lu::Operation::OL, " Example three")},
    {lu::Token(lu::Operation::OL, " Example four")}
  };
  REQUIRE(
    tokenizer.tokens == tokens
  );
}

TEST_CASE("Tokenizes a paragraph") {
  const lu::Tokenizer tokenizer(
    "First sentance.\n"
    " Second sentance."
  );
  const auto tokens = std::vector<lu::Token> {
    {lu::Token(lu::Operation::P, "First sentance.")},
    {lu::Token(lu::Operation::P, " Second sentance.")}
  };
  REQUIRE(
    tokenizer.tokens == tokens
  );
}

