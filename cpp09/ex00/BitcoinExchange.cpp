/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:52:23 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/18 16:54:13 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::printExchange(
 const std::map<std::string, float>& exchangeData,
 const std::map<std::string, float>& btcAmount) {
  
}

BitcoinExchange::BitcoinExchange()
{
  throw std::runtime_error("Instantiation of a static BitcoinExchange class");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  (void)other;
  throw std::runtime_error("Instantiation of a static BitcoinExchange class");
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  (void)other;
  throw std::runtime_error("Instantiation of a static BitcoinExchange class");
}

BitcoinExchange::~BitcoinExchange() {}