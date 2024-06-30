/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:20:32 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 10:55:16 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog(): Animal("Dog") {
  LAY_BLUE("Constructor: ");
  PUT_GREEN("You adopt a new Dog!");
}

Dog::Dog(const Dog& other): Animal(other.type) {}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

Dog::~Dog() {
  LAY_RED("Destructor: ");
  PUT_GREEN("Dog");
}

void Dog::makeSound() const {
  PUT_GREEN("Dog BARKS");
}
