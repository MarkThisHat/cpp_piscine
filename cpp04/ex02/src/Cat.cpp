/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:39:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 16:10:20 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

Cat::Cat(): AAnimal("Cat"), brain(new Brain()) {
  LAY_BLUE("Constructor: ");
  PUT_YELLOW("You are adopted by a new Cat!");
}

Cat::Cat(const Cat& other): AAnimal(other.type), brain(new Brain(*other.brain))
{}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    AAnimal::operator=(other);
    *brain = *other.brain;
  }
  return *this;
}

Cat::~Cat() {
  LAY_RED("Destructor: ");
  PUT_YELLOW("Cat");
  delete brain;
}

void Cat::makeSound() const {
  PUT_YELLOW("Cat MEOWS");
}

const Brain& Cat::getBrain() const {
  return *brain;
}

void Cat::setBrainIdea(const std::string& idea, int index) {
  brain->setIdea(idea, index);
}
