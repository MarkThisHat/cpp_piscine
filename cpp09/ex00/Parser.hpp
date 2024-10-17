/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:15:49 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/17 17:03:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ifstream>
#include <map>
#include <string>

class Parser {
 public:
  static std::map<std::string, float> fileParse(std::ifstream file);

 private:
  Parser();
  Parser(const Parser& other);
  Parser& operator=(const Parser& other);
  ~Parser();
};
