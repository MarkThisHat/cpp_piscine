/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:49 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/21 16:45:48 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <stdexcept>

class Parser {
 public:
  static void parseInput(
    const std::string& input, std::stack<int>& operands,
    std::stack<int (*)(int, int)>& functions, size_t i = 0);


 private:
  static bool validateOperator(char c);
  static bool validateInput(const std::string& str, size_t i);
  static void stack(const char c,
   std::stack<int>& operands, std::stack<int (*)(int, int)>& functions);

  Parser();
  Parser(const Parser& other);
  Parser& operator=(const Parser& other);
  ~Parser();
};

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);