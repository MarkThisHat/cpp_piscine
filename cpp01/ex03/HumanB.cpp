/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:27:13 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 12:57:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name): name_(name), weapon_(NULL)
{}

HumanB::HumanB(std::string name, Weapon &weapon): name_(name), weapon_(&weapon)
{}

HumanB::~HumanB() {}

void HumanB::attack() const {
  std::cout << getName() << " attacks with their "
            << (weapon_ ? weapon_->getType() : "*bare hands*")
            << "!" << std::endl;
}

std::string HumanB::getName() const {
  return name_;
}

void HumanB::setWeapon(Weapon& weapon) {
  if (weapon_) {
    unsetWeapon();
  }
  weapon_ = &weapon;
  std::cout << name_ << " picks up " << weapon_->getType() << "." << std::endl;
}

void HumanB::unsetWeapon() {
  std::cout << name_;
  if (weapon_ == NULL) {
    std::cout << " is already unarmed!";
  } else {
    std::cout << " puts down " << weapon_->getType() << ".";
    weapon_ = NULL;
  }
  std::cout << std::endl;
}
