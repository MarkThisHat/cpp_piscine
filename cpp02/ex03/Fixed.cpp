/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:16:56 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 16:03:42 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(): fixedPointValue(0) {}

Fixed::Fixed(const Fixed& other): fixedPointValue(other.fixedPointValue) {}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    fixedPointValue = other.fixedPointValue;
  }
  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
  return fixedPointValue;
}

void Fixed::setRawBits(const int value) {
  fixedPointValue = value;
}

Fixed::Fixed(const int value) {
  fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
  fixedPointValue = roundf(value * (1 << fractionalBits));
}

int Fixed::toInt() const {
  return fixedPointValue >> fractionalBits;
}

float Fixed::toFloat() const {
  return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

bool Fixed::operator>(const Fixed& other) const {
  return fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
  return fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
  return fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
  return fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
  return fixedPointValue == other.fixedPointValue;;
}

bool Fixed::operator!=(const Fixed& other) const {
  return fixedPointValue != other.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) {
  Fixed addition;
  addition.fixedPointValue = fixedPointValue + other.fixedPointValue;
  return addition;
}

Fixed Fixed::operator-(const Fixed& other) {
  Fixed subtraction;
  subtraction.fixedPointValue = fixedPointValue - other.fixedPointValue;
  return subtraction;
}

Fixed Fixed::operator/(const Fixed& other) {
  Fixed division;
  division.fixedPointValue =
    (fixedPointValue * (1 << fractionalBits))
      / other.fixedPointValue;
  return division;
}

Fixed Fixed::operator*(const Fixed& other) {
  Fixed multiplication;
  multiplication.fixedPointValue = 
    (fixedPointValue * other.fixedPointValue)
      / (1 << fractionalBits);
  return multiplication;
}

Fixed &Fixed::operator++() {
  fixedPointValue += 1;
  return *this;
}

Fixed &Fixed::operator--() {
  fixedPointValue -= 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  fixedPointValue += 1;
  return temp;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  fixedPointValue -= 1;
  return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return (a.fixedPointValue < b.fixedPointValue) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a.fixedPointValue < b.fixedPointValue) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return (a.fixedPointValue > b.fixedPointValue) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a.fixedPointValue > b.fixedPointValue) ? a : b;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
