/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:20:32 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 15:05:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain()) {
  LAY_BLUE("Constructor: ");
  PUT_GREEN("You adopt a new Dog!");
}

Dog::Dog(const Dog& other): Animal(other.type), brain(new Brain(*other.brain))
{}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
    *brain = *other.brain;
  }
  return *this;
}

Dog::~Dog() {
  LAY_RED("Destructor: ");
  PUT_GREEN("Dog");
  delete brain;
}

void Dog::makeSound() const {
  PUT_GREEN("Dog BARKS");
}

const Brain& Dog::getBrain() const {
  return *brain;
}

void Dog::setBrainIdea(const std::string& idea, int index) {
  brain->setIdea(idea, index);
}