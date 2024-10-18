/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:40:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/17 23:12:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <iostream>

int main(int argc, char** argv) {
  std::string input = (argc > 1) ? argv[1] : "";

  std::ifstream dataFile("data.csv");
  if (!dataFile.is_open()) {
    std::cerr << "Error: opening data.csv file" << std::endl;
    return -1;
  }

  std::map<std::string, float> dateValueMap;
  Parser::fileParse(dataFile, dateValueMap, ',');

  std::ifstream inputFile(input.c_str());
  if (!inputFile.is_open() || inputFile.fail() || argc < 2) {
    std::cerr << "Error: could not open file" << std::endl;
    dataFile.close();
    return -1;
  }

  dataFile.close();
  inputFile.close();
  return 0;
}
