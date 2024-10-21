/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:59:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/21 16:52:01 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

void Parser::parseInput(const std::string& input, std::stack<int>& operands,
 std::stack<int (*)(int, int)>& functions, size_t i) {
  if (i >= input.length()) return;
  parseInput(input, operands, functions, i + 1);

  if (validateInput(input, i)) {
    stack(input[i], operands, functions);
  } else if (!std::isspace(input[i])) {
    throw std::invalid_argument("Error");
  }
}

void Parser::stack(const char c,
 std::stack<int>& operands, std::stack<int (*)(int, int)>& functions) {
  if (!validateOperator(c)) {
    operands.push(c - '0');
    return;
  }

  switch(c) {
    case '+':
      functions.push(&add);
      break;
    case '-':
      functions.push(&subtract);
      break;
    case '*':
      functions.push(&multiply);
      break;
    case '/':
      functions.push(&divide);
      break;
    default:
      throw std::runtime_error("Invalid operand was parsed");
  }
}

bool Parser::validateOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

bool Parser::validateInput(const std::string& str, size_t i) {
  size_t length = str.length();

  return (std::isdigit(str[i]) || validateOperator(str[i])) &&
   (i == length - 1 || str[i + 1] == ' ') && (i == 0 || str[i - 1] == ' ');
}

Parser::Parser() {
  throw std::runtime_error("Instantiation of a static Parser class");
}

Parser::Parser(const Parser& other) {
  (void)other;
  throw std::runtime_error("Instantiation of a static Parser class");
}

Parser& Parser::operator=(const Parser& other) {
  (void)other;
  throw std::runtime_error("Instantiation of a static Parser class");
}

Parser::~Parser() {};
