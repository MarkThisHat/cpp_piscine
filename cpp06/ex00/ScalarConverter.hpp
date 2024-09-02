/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:08:56 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/02 13:58:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cerrno>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>

#define BASE_INT 10

# ifndef INT_MAX
#  define INT_MAX (2147483647)
# endif

# ifndef INT_MIN
#  define INT_MIN (-2147483647-1)
# endif

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter&);
  ScalarConverter& operator=(const ScalarConverter&);

  static void tryChar(const std::string& str);
  static char toChar(int i);
  static void printChar(char c);

  static void tryInt(const std::string& str);
  static int toInt(const std::string& str);

  static void tryFloat(const std::string& str);
  static float toFloat(const std::string& str);
  static void printFloat(float c);

  static void tryDouble(const std::string& str);
  static double toDouble(const std::string& str);

 public:
  static void convert(const std::string& str);
};
