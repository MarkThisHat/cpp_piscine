/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:45:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/12 09:31:16 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) const {
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  void (Harl::*functions[])() const = 
    { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

  int i = 0;
  while (i < 4 && level != levels[i])
    i++;

  (i < 4) ? (this->*functions[i])() : void(0);
}

void Harl::debug() const {
  std::cout << Harl::DEBUG << std::endl;
}

void Harl::info() const {
  std::cout << Harl::INFO << std::endl;
}

void Harl::warning() const {
  std::cout << Harl::WARNING << std::endl;
}

void Harl::error() const {
  std::cout << Harl::ERROR << std::endl;
}

const std::string Harl::DEBUG = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
const std::string Harl::INFO = "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
const std::string Harl::WARNING = "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.";
const std::string Harl::ERROR = "This is unacceptable! I want to speak to the manager now.";
