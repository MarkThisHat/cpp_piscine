/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:53:26 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/03 19:43:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria("ice") {
  (void)other;
}

Ice& Ice::operator=(const Ice& other) {
  if (this != &other) {
    type = "ice";
  }
  return *this;
}

const std::string& Ice::getType() const {
  return type;
}

AMateria* Ice::clone() const {
  return new Ice();
}

void Ice::use(ICharacter& target) {
  PUT_BLUE("* shoots an ice bolt at " + target.getName() + " *");
}

Ice::~Ice() {};
