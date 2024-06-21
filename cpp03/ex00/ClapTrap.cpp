/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:11:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 21:32:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name): name(name), active(true),
 hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "A wild ClapTrap " << name << " appears!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): name(other.name), active(other.active),
 hitPoints(other.hitPoints), energyPoints(other.energyPoints),
 attackDamage(other.attackDamage) {
  std::cout << "Another wild ClapTrap " << name << " appears!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    std::cout << "Yet another ClapTrap " << name << " appears!" << std::endl;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    active = other.active;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  std::cout << "ClapTrap " << name;
  if (!active || !energyPoints) {
    std::cout << " is unable to attack!";
  } else {
    energyPoints -= 1;
    std::cout << " attacks " << target << " for [" << attackDamage
      << (attackDamage > 0 ? "] damage! (" : "] - no harm done! (")
      << energyPoints << ") energy points left).";
    active = (energyPoints > 0 ? true : false);
  }
  std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  unsigned int damage = (amount < hitPoints) ? amount : hitPoints;
  std::cout << "ClapTrap " << name << " takes " 
    << (damage > 0 ? "[" : "no [") << damage << "] damage!" << std::endl;
  hitPoints -= damage;
  active = (hitPoints > 0 ? true : false);
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "ClapTrap " << name;
  if (!active || !energyPoints || !amount) {
    std:: cout << " is unable to repair itself!";
  } else {
    energyPoints -= 1;
    std::cout << " repairs [" << amount << "] damage! ("
      << energyPoints << ") energy points left).";
    hitPoints += amount;
    active = (energyPoints > 0 ? true : false);
  }
  std::cout << std::endl;
}
