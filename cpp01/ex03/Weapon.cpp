/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:06:45 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/09 13:02:12 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type_(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const {
  return type_;
}

void Weapon::setType(const std::string& type) {
  if (type.empty()) {
    type_ = "Default";
  } else {
    type_ = type;
  }
}
