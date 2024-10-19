/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:40:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/19 13:46:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Parser.hpp"

int main(int argc, char** argv) {
  std::string input = (argc > 1) ? argv[1] : "";

  std::ifstream dataFile("data.csv");
  if (!dataFile.is_open() || dataFile.fail()) {
    std::cerr << "Error: opening data.csv file" << std::endl;
    return -1;
  }

  std::map<std::string, float> dateValueMap;

  try {
    Parser::fileParse(dataFile, dateValueMap);
  } catch (std::exception& e) {
    std::cerr << "Error: data.csv " << e.what() << std::endl;
    dataFile.close();
    return -1;
  }
  dataFile.close();

  std::ifstream inputFile(input.c_str());
  if (!inputFile.is_open() || inputFile.fail() || argc < 2) {
    std::cerr << "Error: could not open file" << std::endl;
    return -1;
  }
  BitcoinExchange exchange(dateValueMap);

  std::string line;
  std::getline(inputFile, line);
  while(std::getline(inputFile, line)) {
    std::string trimmedInput;
    try {
      trimmedInput = Parser::inputFormat(line);
    } catch(std::exception& e) {
      std::cerr << e.what() << " => " << input << std::endl;
    }
    exchange.makeExchange(trimmedInput);
  }
  inputFile.close();

  return 0;
}
