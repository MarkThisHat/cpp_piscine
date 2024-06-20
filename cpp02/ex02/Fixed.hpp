/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:39:03 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 15:51:18 by maalexan         ###   ########.fr       */
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
  Fixed& operator=(const Fixed &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);
  int toInt() const;
  float toFloat() const;

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed operator+(const Fixed& other);
  Fixed operator-(const Fixed& other);
  Fixed operator/(const Fixed& other);
  Fixed operator*(const Fixed& other);

  Fixed& operator++();
  Fixed& operator--();
  Fixed operator++(int);
  Fixed operator--(int);

  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

 private:
  int fixedPointValue;
  static const int fractionalBits;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
