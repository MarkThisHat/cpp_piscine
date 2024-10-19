/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:59:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/19 13:52:41 by maalexan         ###   ########.fr       */
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

int Parser::intParse(const std::string& str) {
  int value;
  std::istringstream iss(str);

  iss >> value;

  if (iss.fail()) {
    throw std::invalid_argument("Error: bad input");
  }
  return value;
}

std::string Parser::dateParse(const std::string& rawKey) {
  size_t first = rawKey.find('-');
  size_t second = rawKey.find('-', first + 1);

  std::string yearStr = rawKey.substr(0, first);
  std::string monthStr = rawKey.substr(first + 1, second - first - 1);
  std::string dayStr = rawKey.substr(second + 1);

  int year = intParse(yearStr);
  int month = intParse(monthStr);
  int day = intParse(dayStr);

  validDate(year, month, day);
  return rawKey;
}

float Parser::floatParse(const std::string& rawValue) {
  float result;
  std::istringstream iss(rawValue);

  iss >> result;

  if (iss.fail()) {
    throw std::invalid_argument("contains invalid number");
  }
  return result;
}

void Parser::fileParse(std::ifstream& file, std::map<std::string, float>& map) {
  std::string line;
  std::getline(file, line);
  if (line != "date,exchange_rate") {
    throw std::invalid_argument("line 1 is unformatted");
  }
  while (std::getline(file, line)) {
    size_t delimiterPos = line.find(',');
    if (delimiterPos != std::string::npos) {
      std::string key = dateParse(line.substr(0, delimiterPos));
      float value = floatParse(line.substr(delimiterPos + 1));
      map[key] = value;
    }
  }
}

std::string Parser::trim(const std::string& str) {
  size_t start = 0;
  while (start < str.size() && std::isspace(str[start])) {
    start++;
  }
  size_t end = str.size();
  while (end > start && std::isspace(str[end - 1])) {
    end--;
  }
  return str.substr(start, end - start);
}

std::string Parser::inputFormat(const std::string& input) {
  size_t pipePos = input.find('|');

  if (pipePos == std::string::npos) {
    throw std::invalid_argument("Error: bad input");
  }
  std::string datePart = trim(input.substr(0, pipePos));
  std::string numberPart = trim(input.substr(pipePos + 1));

  if (datePart == "" || numberPart == "") {
    throw std::invalid_argument("Error: bad input");
  }

  return datePart + "," + numberPart;
}

void Parser::validDate(int year, int month, int day) {
  if (month >= 1 && month <= 12 && year <= 2024 && year >= 2009) {
    int daysInMonth[] = { 31, leapYear(year) ? 29 : 28, 31,\
     30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day > 0 && day <= daysInMonth[month - 1]) {
      return;
    }
  }
  throw std::invalid_argument("bad input");
}

bool Parser::leapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
