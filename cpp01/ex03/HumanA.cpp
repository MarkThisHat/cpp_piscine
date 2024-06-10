/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:27:13 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 12:47:35 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name_(name), weapon_(weapon)
{}

HumanA::~HumanA() {}

void HumanA::attack() const {
  std::cout << getName() << " attacks with their "
            << weapon_.getType() << "!" << std::endl;
}

std::string HumanA::getName() const {
  return name_;
}

void HumanA::setWeapon(Weapon& weapon) {
  std::cout << getName() << " puts down " << weapon_.getType() << ".\n";
  weapon_ = weapon;
  std::cout << name_ << " picks up " << weapon_.getType() << "." << std::endl;
}
