/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:30:19 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 17:08:53 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& other);
  WrongCat& operator=(const WrongCat& other);
  ~WrongCat();
  void makeSound() const;
};
