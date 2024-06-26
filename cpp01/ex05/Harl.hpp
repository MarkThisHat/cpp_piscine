/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:02:04 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/12 09:18:58 by maalexan         ###   ########.fr       */
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

  static const std::string DEBUG;
  static const std::string INFO;
  static const std::string WARNING;
  static const std::string ERROR;

 private:
  void debug() const;
  void info() const;
  void warning() const;
  void error() const;
};
