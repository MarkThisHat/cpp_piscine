/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:41:18 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 17:09:27 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

Fixed orientation(Point const p1, Point const p2, Point const p3) {
  return (p1.getX() - p3.getX()) * 
         (p2.getY() - p3.getY()) - 
         (p2.getX() - p3.getX()) * 
         (p1.getY() - p3.getY());
}

bool collinearity(Point const a, Point const b, Point const point) {
  return orientation(a, b, point) == 0 && 
         point.getX() >= Fixed::min(a.getX(), b.getX()) &&
         point.getX() <= Fixed::max(a.getX(), b.getX()) &&
         point.getY() >= Fixed::min(a.getY(), b.getY()) &&
         point.getY() <= Fixed::max(a.getY(), b.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  if (collinearity(a, b, point) ||
      collinearity(b, c, point) ||
      collinearity(c, a, point)) {
      return false;
  }

  Fixed d1 = orientation(point, a, b);
  Fixed d2 = orientation(point, b, c);
  Fixed d3 = orientation(point, c, a);

  bool negativeOrientation = (d1 < 0) || (d2 < 0) || (d3 < 0);
  bool positiveOrientation = (d1 > 0) || (d2 > 0) || (d3 > 0);

  return !(negativeOrientation && positiveOrientation);
}
