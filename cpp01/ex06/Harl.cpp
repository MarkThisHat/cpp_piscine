/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:45:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/12 10:53:36 by maalexan         ###   ########.fr       */
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

  switch (i)
  {
    case DEBUG:
      (this->*functions[DEBUG])();
      std::cout << std::endl;
      // Intentional fallthrough
    case INFO:
      (this->*functions[INFO])();
      std::cout << std::endl;
      // Intentional fallthrough
    case WARNING:
      (this->*functions[WARNING])();
      std::cout << std::endl;
      // Intentional fallthrough
    case ERROR:
      (this->*functions[ERROR])();
      break;
    default:
      std::cout << Harl::OTHER_STR << std::endl;
  }
}

void Harl::debug() const {
  std::cout << Harl::DEBUG_STR << std::endl;
}

void Harl::info() const {
  std::cout << Harl::INFO_STR << std::endl;
}

void Harl::warning() const {
  std::cout << Harl::WARNING_STR << std::endl;
}

void Harl::error() const {
  std::cout << Harl::ERROR_STR << std::endl;
}

const std::string Harl::DEBUG_STR = "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
const std::string Harl::INFO_STR = "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
const std::string Harl::WARNING_STR = "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.";
const std::string Harl::ERROR_STR = "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.";
const std::string Harl::OTHER_STR = "[ Probably complaining about insignificant problems ]";
