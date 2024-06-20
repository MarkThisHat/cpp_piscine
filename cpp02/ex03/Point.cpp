/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:28:52 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 16:37:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(const float x, const float y): x(x), y(y) {}

Point::Point(const Point &other): x(other.x), y(other.y) {}

Point &Point::operator=(const Point& other) {
  if (this != &other) {
    const_cast<Fixed&>(x) = other.x;
    const_cast<Fixed&>(y) = other.y;
  }
  return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
  return x;
}

Fixed Point::getY() const {
  return y;
}
