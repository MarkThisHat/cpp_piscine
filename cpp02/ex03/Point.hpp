/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:16:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 16:35:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {
 public:
  Point();
  Point(const float x, const float y);
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point();

  Fixed getX() const;
  Fixed getY() const;

 private:
  const Fixed x;
  const Fixed y;
};
