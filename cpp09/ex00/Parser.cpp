/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:59:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/17 22:59:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser() {
  throw std::runtime_error("Instantiation of a static Parser class");
}

Parser::Parser(const Parser& other) {
  (void)other;
  throw std::runtime_error("Instantiation of a static Parser class");
}

Parser& Parser::operator=(const Parser& other) {
  (void)other;
  throw std::runtime_error("Instantiation of a static Parser class");
}

Parser::~Parser() {};

std::string Parser::dateParse(const std::string& rawKey) {
  size_t first = rawKey.find('-');
  size_t second = rawKey.find('-', first + 1);

  std::string yearStr = rawKey.substr(0, first);
  std::string monthStr = rawKey.substr(first + 1, second - first - 1);
  std::string dayStr = rawKey.substr(second + 1);

  int year, month, day;

  std::istringstream(yearStr) >> year;
  std::istringstream(monthStr) >> month;
  std::istringstream(dayStr) >> day;

  validDate(year, month, day);
  return rawKey;
}

float Parser::valueParse(const std::string& rawValue, char delim) {
  float result;
  float maximum = (delim == ',' ? MAX_BTC : 1000);

  std::istringstream(rawValue) >> result;
  if (result >= maximum) {
    throw std::invalid_argument("File contains invalid value");
  }
  return result;
}

void Parser::fileParse(
 std::ifstream& file, std::map<std::string, float>& dataMap, char delim) {
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    size_t delimiterPos = line.find(delim);
    if (delimiterPos != std::string::npos) {
      std::string key = dateParse(line.substr(0, delimiterPos));
      float value = valueParse(line.substr(delimiterPos + 1), delim);
      dataMap[key] = value;
    }
  }
}

void Parser::validDate(int year, int month, int day) {
  if (month >= 1 && month <= 12 && year <= 2024 && year >= 2009) {
    int daysInMonth[] = { 31, leapYear(year) ? 29 : 28, 31,\
     30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day > 0 && day <= daysInMonth[month - 1]) {
      return;
    }
  }
  throw std::invalid_argument("File contains invalid date");
}

bool Parser::leapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

