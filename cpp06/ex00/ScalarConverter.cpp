/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:39:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/01 21:09:41 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& str) {
  tryChar(str);
  tryInt(str);
}

void ScalarConverter::tryChar(const std::string& str) {
  std::cout << "char: ";
  try {
    int i = (str.length() == 1) ? static_cast<int>(str[0]) : toInt(str);
    char c = toChar(i);
    printChar(c);
  } catch (std::exception& e) {
    std::cout << "impossible";
  }
  std::cout << std::endl;
}

void ScalarConverter::tryInt(const std::string& str) {
  std::cout << "int: ";
  try {
    int i = toInt(str);
    std::cout << i;
  } catch (std::exception& e) {
    std::cout << "impossible";
  }
  std::cout << std::endl;
}

char ScalarConverter::toChar(int i) {
  if (i < 0 || i > 255) {
    throw std::invalid_argument("Outside char boundaries");
  }
  return static_cast<char>(i);
}

void ScalarConverter::printChar(char c) {
  std::cout << (std::isprint(c) ? 
                "'" + std::string(1, c) + "'" :
                "Non displayable");
}

int ScalarConverter::toInt(const std::string& str) {
  errno = 0;
  const char* convertedString = str.c_str();
  char* endOfConverted;

  long result = std::strtol(convertedString, &endOfConverted, BASE_INT);
  if (convertedString == endOfConverted) {
    throw std::invalid_argument("Input cannot be converted to int");
  }
  if (errno == ERANGE || result > INT_MAX || result < INT_MIN) {
    throw std::out_of_range("Value outside boundries for an integer");
  }
  return static_cast<int>(result);
}
