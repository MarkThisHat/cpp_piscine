/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:49:00 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 17:09:41 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

int main() {
  Point a(0.0f, 0.0f);
  Point b(5.0f, 0.0f);
  Point c(2.5f, 5.0f);

  Point pInside(2.5f, 2.0f);
  Point pOutside(5.0f, 5.0f);
  Point pEdge(2.5f, 0.0f);
  Point pVertex(0.0f, 0.0f);

  bool result1 = bsp(a, b, c, pInside);
  bool result2 = bsp(a, b, c, pOutside);
  bool result3 = bsp(a, b, c, pEdge);
  bool result4 = bsp(a, b, c, pVertex);

  std::cout << "Point pInside is " << (result1 ? "inside" : "outside")
            << " the triangle." << std::endl;
  std::cout << "Point pOutside is " << (result2 ? "inside" : "outside")
            << " the triangle ." << std::endl;
  std::cout << "Point pEdge is " << (result3 ? "inside" : "outside")
            << " the triangle." << std::endl;
  std::cout << "Point pVertex is " << (result4 ? "inside" : "outside")
            << " the triangle." << std::endl;

  return 0;
}
