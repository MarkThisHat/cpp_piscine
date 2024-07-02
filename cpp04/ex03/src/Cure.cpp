/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:53:26 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/02 20:42:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria("cure") {
  (void)other;
}

Cure& Cure::operator=(const Cure& other) {
  if (this != &other) {
    type = "cure";
  }
  return *this;
}

const std::string& Cure::getType() const {
  return type;
}

AMateria* Cure::clone() const {
  return new Cure();
}

void Cure::use(ICharacter& target) {
  PUT_BLUE("* heals " + target.getName() + "'s wounds *");
}

Cure::~Cure() {};
