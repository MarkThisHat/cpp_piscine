/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:40:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/17 22:33:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <iostream>

int main(int argc, char** argv) {
  std::string input = (argc > 1) ? argv[1] : argv[0];

  std::ifstream dataFile ("data.csv");
  if (!dataFile.is_open()) {
    std::cerr << "Error: opening file" << std::endl;
    return -1;
  }
  
  std::map<std::string, float> dateValueMap;
  Parser::fileParse(dataFile, dateValueMap, ',');

  std::cout << input << std::endl;
  return 0;
}
