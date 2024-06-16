/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:49:38 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/16 18:12:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(): fixedPointNumberValue(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): fixedPointNumberValue(other.fixedPointNumberValue) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    fixedPointNumberValue = other.fixedPointNumberValue;
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixedPointNumberValue;
}

void Fixed::setRawBits(const int value) {
  fixedPointNumberValue = value;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  fixedPointNumberValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  fixedPointNumberValue = roundf(value * (1 << fractionalBits));
}

int Fixed::toInt() const {
  return fixedPointNumberValue >> fractionalBits;
}

float Fixed::toFloat() const {
  return static_cast<float>(fixedPointNumberValue) / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}