/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:45:09 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/19 13:27:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#define MAX_BTC 1000

class BitcoinExchange {
 public:
  BitcoinExchange(const std::map<std::string, float>& dataMap);
  BitcoinExchange(const BitcoinExchange& other);
  ~BitcoinExchange();

  void makeExchange(const std::string& input) const;

 private:
  const std::map<std::string, float>& data;

  bool validateValue(const float value) const;
  BitcoinExchange();
  BitcoinExchange& operator=(const BitcoinExchange& other);
};
