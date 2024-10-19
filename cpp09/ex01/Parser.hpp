/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:49 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/19 18:02:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <stdexcept>

class Parser {
 public:
  bool parseInput(const std::string& input,
   std::stack<int (*)(int, int)>& functions, std::stack<int>& operands);


 private:
  bool Parser::validateOperator(char c);
  bool Parser::validateInput(const std::string& str, size_t i);
  void Parser::stack(const char c,
   std::stack<int (*)(int, int)>& functions, std::stack<int>& operands);

  Parser();
  Parser(const Parser& other);
  Parser& operator=(const Parser& other);
  ~Parser();
};

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);