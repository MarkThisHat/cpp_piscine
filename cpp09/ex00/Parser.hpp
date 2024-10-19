/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:49 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/19 13:46:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <map>
#include <sstream>
#include <string>

class Parser {
 public:
  static void fileParse(std::ifstream& file, std::map<std::string, float>& map);
  static std::string inputFormat(const std::string& input);
  static std::string dateParse(const std::string& rawKey);
  static float floatParse(const std::string& rawValue);

 private:
  Parser();
  Parser(const Parser& other);
  Parser& operator=(const Parser& other);
  ~Parser();

  static std::string trim(const std::string& str);
  static int intParse(const std::string& rawValue);
  static void validDate(int year, int month, int day);
  static bool leapYear(int year);
};
