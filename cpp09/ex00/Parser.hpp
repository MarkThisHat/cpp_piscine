/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:49 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/17 23:00:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <map>
#include <sstream>
#include <string>

class Parser {
 public:
  static void fileParse(
   std::ifstream& file, std::map<std::string, float>& dataMap, char delim);

 private:
  Parser();
  Parser(const Parser& other);
  Parser& operator=(const Parser& other);
  ~Parser();

  static float valueParse(const std::string& rawValue, char delim);
  static std::string dateParse(const std::string& rawKey);
  static void validDate(int year, int month, int day);
  static bool leapYear(int year);
};

#define MAX_BTC 2147483647
