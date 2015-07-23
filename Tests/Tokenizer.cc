#include <vector>

#include "catch.hpp"
#include "Token.h"
#include "Tokenizer.h"

TEST_CASE("Tokenizes headers") {
  const lu::Tokenizer tokenizer(
    "# Hello\n"
    "## Hello\n"
    "### Hello\n"
    "#### Hello\n"
    "##### Hello\n"
    "###### Hello"
  );
  const auto tokens = std::vector<lu::Token> {
    lu::Token(lu::Operation::H1, " Hello"),
    lu::Token(lu::Operation::H2, " Hello"),
    lu::Token(lu::Operation::H3, " Hello"),
    lu::Token(lu::Operation::H4, " Hello"),
    lu::Token(lu::Operation::H5, " Hello"),
    lu::Token(lu::Operation::H6, " Hello")
  };
  REQUIRE(tokenizer.tokens == tokens);
}

TEST_CASE("Tokenizes lists") {
  const lu::Tokenizer tokenizer(
    "* Example one\n"
    "+ Example two\n"
    "- Example three\n"
    "1. Example four\n"
    "2. Example five"
  );
  // Can't directly pass in vector literal with multiple elements.
  const auto tokens = std::vector<lu::Token> {
    {lu::Token(lu::Operation::UL, " Example one")},
    {lu::Token(lu::Operation::UL, " Example two")},
    {lu::Token(lu::Operation::UL, " Example three")},
    {lu::Token(lu::Operation::OL, " Example four")},
    {lu::Token(lu::Operation::OL, " Example five")}
  };
  REQUIRE(
    tokenizer.tokens == tokens
  );
}

TEST_CASE("Tokenizes sub-lists") {
  const lu::Tokenizer tokenizer(
    "1. Example one\n"
    "    1. Example two"
  );
  lu::Token token(lu::Operation::OL, " Example one");
  token.childTokens = new std::vector<lu::Token>;
  token.childTokens->push_back(
    lu::Token(lu::Operation::OL, " Example two")
  );
  REQUIRE(
    tokenizer.tokens == std::vector<lu::Token> {
      {token}
    }
  );
}

TEST_CASE("Tokenizes paragraphs") {
  const lu::Tokenizer tokenizer(
    "First sentance.\n"
    " Second sentance.\n\n"
    "Second paragraph."
  );
  const auto tokens = std::vector<lu::Token> {
    lu::Token(
      lu::Operation::P, "First sentance. Second sentance."
    ),
    lu::Token(
      lu::Operation::Blank, ""
    ),
    lu::Token(
      lu::Operation::P, "Second paragraph."
    ),
  };
  REQUIRE(
    tokenizer.tokens == tokens
  );
}

