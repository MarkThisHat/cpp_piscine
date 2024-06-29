/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:08:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 15:58:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("") {
  PUT_WHITE("Base animal constructed");
}

Animal::Animal(const std::string &type): type(type) {}

Animal::Animal(const Animal& other): type(other.type) {}

Animal& Animal::operator=(const Animal& other) {
 if (this != &other) {
  type = other.type;
 }
 return *this;
}

Animal::~Animal() {}

void Animal::makeSound() const {
  PUT_WHITE("Makes Animal noises");
}

const std::string Animal::getType() const {
  return type;
}