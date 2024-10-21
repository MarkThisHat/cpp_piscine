/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:59:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/21 17:41:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

void Parser::parseInput(const std::string& input, std::stack<int>& operands,
 std::stack<int (*)(int, int)>& functions) {
  (void) input;
  (void) operands;
  (void) functions;
}

std::string Parser::cleanInput(const std::string& input) {
  std::string trimmedInput;

  for (size_t i = 0; i < input.length(); i++) {
    if (validateInput(input, i)) {
      trimmedInput += input[i];
    } else if (!std::isspace(input[i])) {
      throw std::invalid_argument("Error");
    }
  }
  return trimmedInput;
}

void Parser::stack(const char c,
 std::stack<int>& operands, std::stack<int (*)(int, int)>& functions) {
  if (!validateOperator(c)) {
    operands.push(c - '0');
    return;
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

int (*Parser::getFunction(char c))(int, int) {
  switch(c) {
    case '+':
      return (&add);
      break;
    case '-':
      return (&subtract);
      break;
    case '*':
      return (&multiply);
      break;
    case '/':
      return (&divide);
      break;
    default:
      throw std::runtime_error("Invalid operand was parsed");
  }
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
