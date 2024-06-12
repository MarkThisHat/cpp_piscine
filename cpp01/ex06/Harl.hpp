/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:02:04 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/12 10:53:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Harl {
 public:
  Harl() {}
  ~Harl() {}
  void complain(std::string level) const;

  static const std::string DEBUG_STR;
  static const std::string INFO_STR;
  static const std::string WARNING_STR;
  static const std::string ERROR_STR;
  static const std::string OTHER_STR;

 private:
  void debug() const;
  void info() const;
  void warning() const;
  void error() const;

  enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR
  };
};
