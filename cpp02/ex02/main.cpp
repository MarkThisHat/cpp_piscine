/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:45:27 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 15:50:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  return 0;
}

/* Uncomment for debug main:
int main( void ) {
  std::cout << "Fixed a; ->\t";
  Fixed a;
  std::cout << "Fixed b(a); ->\t";
  Fixed b( a );
  std::cout << "Fixed c; ->\t";
  Fixed c;
  std::cout << "c = b; ->\t";
  c = b;
  std::cout << "Calling rawbits 3x now:" << std::endl;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  std::cout << "exiting main" << std::endl;
  return 0;
}
*/