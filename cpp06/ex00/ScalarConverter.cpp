/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:39:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/01 10:56:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

void ScalarConverter::convert(const std::string& str) {
  try {
    int i = toInt(str);
    std::cout << "Success! Int: " << i;
  } catch (std::exception& e) {
    std::cerr << "Error! Couldn't convert because: " << e.what();
  }
  std::cout << std::endl;
}
