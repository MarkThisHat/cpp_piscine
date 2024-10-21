/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:15:25 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/21 17:27:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::operate() {
  while (canOperate()) {
    operation op = operations.top();
    operations.pop();
    int a = operands.top();
    operands.pop();
    int b = operands.top();
    operands.pop();
    operands.push(op(a, b));
  }
  if (sucessfulyOperated()) {
    return operands.top();
  }
  throw std::invalid_argument("Error");
  return -1;
}

bool RPN::canOperate() const {
  return operations.size() >= 1 && operands.size() >= 2;
}

bool RPN::sucessfulyOperated() const {
  return !operations.size() && operands.size() == 1;
}

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other): 
 operands(other.operands), operations(other.operations) {}

RPN& RPN::operator=(const RPN& other) {
  if (this != &other) {
    operands = other.operands;
    operations = other.operations;
  }
  return *this;
}

std::stack<operation>& RPN::getOperations() {
  return operations;
}

std::stack<int>& RPN::getOperands() {
  return operands;
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { if (b != 0) return a / b;
  throw std::invalid_argument("Division by zero"); return 0; }
