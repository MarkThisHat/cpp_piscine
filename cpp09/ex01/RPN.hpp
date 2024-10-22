/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:07:46 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/22 16:38:33 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <stdexcept>

typedef int (*operation)(int, int);

class RPN {
 public:
  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  ~RPN();

  std::stack<int>& getOperands();
  int operate(const std::string& input);
  void doMath(operation op);

 private:
  std::stack<int> operands;

  void validateOperation() const;
  operation getOperation(char c) const;
};


int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);