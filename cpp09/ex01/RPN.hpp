/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:07:46 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/21 17:37:29 by maalexan         ###   ########.fr       */
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
  std::stack<operation>& getOperations();
  int operate();

 private:
  std::stack<int> operands;
  std::stack<operation> operations;

  bool canOperate() const;
  bool sucessfulyOperated() const;
};
