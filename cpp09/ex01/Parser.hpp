/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:49 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/19 18:38:28 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <stdexcept>

class Parser {
 public:
  static void parseInput(const std::string& input,
   std::stack<int (*)(int, int)>& functions, std::stack<int>& operands);


 private:
  static bool validateOperator(char c);
  static bool validateInput(const std::string& str, size_t i);
  static void stack(const char c,
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