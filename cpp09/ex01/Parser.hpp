/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:49 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/22 16:42:55 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

class Parser {
 public:
  static std::string parseInput(const std::string& input);

 private:
  static bool validateOperator(char c);
  static bool validateInput(const std::string& str, size_t i);

  Parser();
  Parser(const Parser& other);
  Parser& operator=(const Parser& other);
  ~Parser();
};

