/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:46:07 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/16 15:07:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed& operator =(const Fixed &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);

 private:
  int fixedPointNumberValue;
  static const int fractionalBits;
};
