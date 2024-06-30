/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:08:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 16:03:25 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AAnimal.hpp"

AAnimal::AAnimal(): type("") {
  LAY_BLUE("Constructor: ");
  PUT_WHITE("AAnimal");
}

AAnimal::AAnimal(const std::string &type): type(type) {}

AAnimal::AAnimal(const AAnimal& other): type(other.type) {}

AAnimal& AAnimal::operator=(const AAnimal& other) {
 if (this != &other) {
  type = other.type;
 }
 return *this;
}

AAnimal::~AAnimal() {
  LAY_RED("Destructor: ");
  PUT_WHITE("AAnimal");
}

const std::string AAnimal::getType() const {
  return type;
}
