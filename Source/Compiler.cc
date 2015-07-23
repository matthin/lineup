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
    case Operation::OL:
    case Operation::UL:
      i += compileList(&html, token, token.operation) - 1;
      break;
    case Operation::Blank:
      break;
    default:
      html += createElement(token.operation, token.text);
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

std::string Compiler::createElement(
  const Operation operation, const std::string& innerText
) const {
  auto operationAsText = operationToText.at(operation);
  std::string openingTag("<" + std::string(operationAsText) + ">");
  std::string closingTag("</" + std::string(operationAsText) + ">");
  return openingTag + innerText + closingTag;
}

} // namespace lu

