/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:36:57 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 11:06:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  ~Dog();

  void makeSound() const;
};
