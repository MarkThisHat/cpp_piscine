/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:15:25 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/19 18:18:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) {}
RPN& RPN::operator=(const RPN& other) {}
RPN::~RPN() {}

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