/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:52:23 by maalexan          #+#    #+#             */
/*   Updated: 2024/11/02 15:35:40 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "BitcoinExchange.hpp"
#include "Parser.hpp"

void BitcoinExchange::makeExchange(const std::string& input) const {
  size_t pipePos = input.find(',');
  std::string date = input.substr(0, pipePos);
  std::string amountStr = input.substr(pipePos + 1);

  try {
    date = Parser::dateParse(date);
  } catch (std::exception& e) {
    std::cerr << e.what() << " => " << date << std::endl;
    return;
  }

  float value = 0;
  try {
    value = Parser::floatParse(amountStr);
  } catch (std::exception& e) {
    std::cerr << e.what() << " => " << amountStr << std::endl;
    return;
  }

  if (!validateValue(value)) {
    return;
  }

  std::map<std::string, float>::const_iterator iter = data.lower_bound(date);
  if (iter == data.end()) {
    iter--;
  }
  std::cout << date << " => " << value << " = "
            << std::fixed << std::setprecision(2)
            << iter->second * value << std::endl;

  std::cout.unsetf(std::ios_base::floatfield);
  std::cout << std::setprecision(6);
}

bool BitcoinExchange::validateValue(const float value) const {
  if (value < 0) {
    std::cerr << "Error: not a positive number" << std::endl;
    return false;
  }

  if (value > MAX_BTC) {
    std::cerr << "Error: too large a number" << std::endl;
    return false;
  }

  return true;
}

BitcoinExchange::BitcoinExchange(const std::map<std::string, float>& dataMap):
data(dataMap) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other):
 data(other.data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    throw std::runtime_error("Assignment operator not allowed");
  }
 return *this;
}

BitcoinExchange::~BitcoinExchange() {}
