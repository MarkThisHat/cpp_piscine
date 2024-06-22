/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:44:57 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/22 14:08:22 by maalexan         ###   ########.fr       */
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
    std::cout << "Yet another ScavTrap " << name << " appears!" << std::endl;
    ClapTrap::operator=(other);
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    guarding = other.guarding;
  }
  return *this;
}

void ScavTrap::guardGate() {
  guarding = !guarding;
  std::cout << "Scavtrap " << name << (guarding ? " starts" : " stops")
    << " guarding the gate!" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name << " starts to disassemble..." << std::endl;
}
