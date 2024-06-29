/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:39:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 12:47:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
  PUT_YELLOW("You are adopted by a new Cat!");
}

Cat::Cat(const Cat& other): Animal(other.type) {}

Cat& Cat::operator=(const Cat& other) {
/*  if (this != &other) {
    type = other.type;
  }*/
 (void)other;
  return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const {
  PUT_YELLOW("Cat MEOWS");
}
