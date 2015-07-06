#include <vector>

#include "Catch.h"
#include "Token.h"
#include "Tokenizer.h"

TEST_CASE("Tokenizes a header") {
  const lu::Tokenizer tokenizer("# Hello");
  REQUIRE(
    tokenizer.tokens == std::vector<lu::Token> {
      {lu::Token(lu::Operation::H1, " Hello")}
    }
  );
}

