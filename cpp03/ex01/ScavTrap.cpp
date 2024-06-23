/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:44:57 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/23 13:10:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name): ClapTrap(name), guarding(false) {
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  std::cout << "A wild ScavTrap " << name << " appears!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other):
 ClapTrap(other), guarding(other.guarding) {
  std::cout << "Another wild ScavTrap " << name << " appears!" << std::endl;       
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    guarding = other.guarding;
    std::cout << "Yet another ScavTrap " << name << " appears!" << std::endl;
  }
  return *this;
}

void ScavTrap::attack(const std::string& target) {
  std::cout << "ScavTrap " << name;
  if (!hitPoints || !spendEnergy(1)) {
    std::cout << " is unable to attack!";
  } else {
    std::cout << " attacks " << target << " for [" << attackDamage
      << (attackDamage > 0 ? "] damage! (" : "] - no harm done! (")
      << energyPoints << ") energy points left.";
  }
  std::cout << std::endl;
}

void ScavTrap::guardGate() {
  guarding = !guarding;
  std::cout << "Scavtrap " << name << (guarding ? " starts" : " stops")
    << " guarding the gate!" << std::endl;
}

bool ScavTrap::guardingStatus() const {
  return guarding;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name << " starts to disassemble..." << std::endl;
}
