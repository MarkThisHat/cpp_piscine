/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:06:22 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 11:07:43 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat: public Animal {
 public:
  Cat();
  Cat(const Cat& other);
  Cat& operator=(const Cat& other);
  ~Cat();

  void makeSound() const;
};
