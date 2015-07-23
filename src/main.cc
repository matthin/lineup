#include <iostream>

#include <Parser.h>

int main(int argc, char* argv[]) {
  std::cout << lu::Parser(argv[1]).toHTML() << std::endl;

  return 0;
}

