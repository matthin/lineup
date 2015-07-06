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

