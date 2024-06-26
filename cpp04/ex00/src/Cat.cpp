/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:39:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 10:55:08 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

Cat::Cat(): Animal("Cat") {
  LAY_BLUE("Constructor: ");
  PUT_YELLOW("You are adopted by a new Cat!");
}

Cat::Cat(const Cat& other): Animal(other.type) {}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

Cat::~Cat() {
  LAY_RED("Destructor: ");
  PUT_YELLOW("Cat");
}

void Cat::makeSound() const {
  PUT_YELLOW("Cat MEOWS");
}
