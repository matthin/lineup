#pragma once

#include <string>

namespace lu {

class Compiler {
public:
  Compiler(const std::string& markdown);
  const std::string html;

private:
  std::string toHTML(const std::string& markdown) const;
};

} // namespace lu

