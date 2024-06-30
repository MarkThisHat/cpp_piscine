/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:39:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 23:21:43 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
  PUT_L_YELLOW("You are adopted by a new WrongCat!");
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other.type) {}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

void WrongCat::makeSound() const {
  PUT_L_YELLOW("This cat meows wrongly");
}

WrongCat::~WrongCat() {}
