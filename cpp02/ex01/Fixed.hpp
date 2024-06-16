/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:46:07 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/16 18:10:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {
 public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);
  Fixed& operator =(const Fixed &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);
  int toInt() const;
  float toFloat() const;

 private:
  int fixedPointNumberValue;
  static const int fractionalBits;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);