/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:08:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 10:58:53 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"

Animal::Animal(): type("") {
  LAY_BLUE("Constructor: ");
  PUT_WHITE("Animal");
}

Animal::Animal(const std::string &type): type(type) {}

Animal::Animal(const Animal& other): type(other.type) {}

Animal& Animal::operator=(const Animal& other) {
 if (this != &other) {
  type = other.type;
 }
 return *this;
}

Animal::~Animal() {
  LAY_RED("Destructor: ");
  PUT_WHITE("Animal");
}

void Animal::makeSound() const {
  PUT_WHITE("Animal makes Animal-like noises");
}

const std::string Animal::getType() const {
  return type;
}
