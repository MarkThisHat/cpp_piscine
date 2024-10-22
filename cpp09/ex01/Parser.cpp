/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:59:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/22 16:42:35 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

std::string Parser::parseInput(const std::string& input) {
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
