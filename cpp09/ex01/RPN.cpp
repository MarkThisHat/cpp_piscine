/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:15:25 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/22 17:00:16 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::operate(const std::string& cleanInput) {
  std::string::const_iterator iter = cleanInput.begin();
  std::string::const_iterator end = cleanInput.end();

  while (iter != end) {
    char c = *iter++;
    (std::isdigit(c)) ? operands.push(c - '0') : doMath(getOperation(c));
  }

  return operationResult(operands.size() == 1);
}

int RPN::operationResult(bool complete) {
  if (!complete) {
    throw std::invalid_argument("Error");
  }
  int result = operands.top();
  operands.pop();
  return result;
}

void RPN::doMath(operation op) {
  if (operands.size() < 2) {
    throw std::invalid_argument("Error");
  }
  int b = operands.top();
  operands.pop();
  int a = operands.top();
  operands.pop();
  operands.push(op(a, b));
}

operation RPN::getOperation(char c) const {
  switch(c) {
    case '+':
      return (&add);
    case '-':
      return (&subtract);
    case '*':
      return (&multiply);
    case '/':
      return (&divide);
    default:
      throw std::runtime_error("Invalid operand");
  }
}

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other): operands(other.operands) {}

RPN& RPN::operator=(const RPN& other) {
  if (this != &other) {
    operands = other.operands;
  }
  return *this;
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { if (b != 0) return a / b;
  throw std::invalid_argument("Division by zero"); return 0; }