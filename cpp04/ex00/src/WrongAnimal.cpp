/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:08:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 11:12:35 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("") {
  LAY_BLUE("Constructor: ");
  PUT_L_PINK("WrongAnimal");
}

WrongAnimal::WrongAnimal(const std::string &type): type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
 if (this != &other) {
  type = other.type;
 }
 return *this;
}

WrongAnimal::~WrongAnimal() {
  LAY_RED("Destructor: ");
  PUT_L_PINK("WrongAnimal");
}

void WrongAnimal::makeSound() const {
  PUT_L_PINK("The sounds this animal makes are just SO WRONG");
}

const std::string WrongAnimal::getType() const {
  return type;
}
