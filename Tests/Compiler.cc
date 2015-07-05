#include "Catch.h"
#include "Compiler.h"

TEST_CASE("Compiles to html") {
  const lu::Compiler compiler("#Hello");
  REQUIRE(compiler.html == "<h1>Hello</h1>");
}

