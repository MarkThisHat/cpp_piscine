/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:02:04 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/11 15:08:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl {
 public:
  static const std::string DEBUG;
  static const std::string INFO;
  static const std::string WARNING;
  static const std::string ERROR;
  void complain(std::string level);

 private:
  void debug();
  void info();
  void warning();
  void error();
};

const std::string Harl::DEBUG = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
const std::string Harl::INFO = "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
const std::string Harl::WARNING = "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.";
const std::string Harl::ERROR = "This is unacceptable! I want to speak to the manager now.";
