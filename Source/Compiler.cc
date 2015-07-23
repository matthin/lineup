#include "Compiler.h"

#include <algorithm>

namespace lu {

Compiler::Compiler(const std::vector<Token> tokens)
    : tokens(tokens){

}

std::string Compiler::toHTML() const {
  std::string html;

  for (int i = 0, length = tokens.size(); i < length; ++i) {
    const auto& token = tokens.at(i);
    switch (token.operation) {
    case Operation::H1:
      html += "<h1>" + token.text + "</h1>";
      break;
    case Operation::H2:
      html += "<h2>" + token.text + "</h2>";
      break;
    case Operation::H3:
      html += "<h3>" + token.text + "</h3>";
      break;
    case Operation::H4:
      html += "<h4>" + token.text + "</h4>";
      break;
    case Operation::H5:
      html += "<H5>" + token.text + "</h5>";
      break;
    case Operation::H6:
      html += "<h6>" + token.text + "</h6>";
      break;
    case Operation::OL:
    case Operation::UL:
      i += compileList(&html, token, token.operation) - 1;
      break;
    case Operation::P:
      html += "<p>" + token.text + "</p>";
      break;
    default:
      // Should log a message saying the operation isn't supported yet.
      break;
    }
  }

  return html;
}

int Compiler::compileList(
  std::string* html, const Token& token, Operation listType,
  const std::vector<Token>& tokens
) const {
  switch (listType) {
  case Operation::OL:
    *html += "<ol>";
    break;
  case Operation::UL:
    *html += "<ul>";
    break;
  default:
    break;
  }

  const auto startPos = std::find(
    tokens.begin(), tokens.end(), token
  ) - tokens.begin();
  int numberOfItems = tokens.size();
  for (int i = startPos, length = tokens.size(); i < length; ++i) {
    const auto& nextToken = tokens.at(i);
    if (nextToken.operation == listType) {
      *html += + "<li>" + nextToken.text;
      if (token.childTokens != nullptr) {
        for (const auto& childToken : *(token.childTokens)) {
          compileList(
            html, childToken, childToken.operation, *(token.childTokens)
          );
        }
      }
      *html += "</li>";
    } else {
      numberOfItems = i;
      break;
    }
  }

  switch (listType) {
  case Operation::OL:
    *html += "</ol>";
    break;
  case Operation::UL:
    *html += "</ul>";
    break;
  default:
    break;
  }

  return numberOfItems;
}

} // namespace lu

