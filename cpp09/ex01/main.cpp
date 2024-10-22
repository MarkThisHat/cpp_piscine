/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:11:01 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/22 16:52:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Parser.hpp"
#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) return -1;

  RPN rpn;

  try {
    std::cout << rpn.operate(Parser::parseInput(argv[1])) << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
