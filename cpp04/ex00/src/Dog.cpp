/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:20:32 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 12:39:20 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
  type = "Dog";
  PUT_GREEN("You adopt a new Dog!");
}

Dog::Dog(const Dog& other): Animal() {
  type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

Dog::~Dog() {}

void Dog::makeSound() const {
  PUT_GREEN("Dog BARKS");
}
