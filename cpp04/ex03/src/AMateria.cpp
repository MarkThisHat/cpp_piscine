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

#include "../incl/AMateria.hpp"


AMateria::AMateria(const std::string& type): type(type) {}

AMateria::AMateria(const AMateria& other): type(other.type) {}

AMateria& AMateria::operator=(const AMateria& other) {
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

const std::string& AMateria::getType() const {
  return type;
}

AMateria::~AMateria() {}
