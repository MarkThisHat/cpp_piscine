/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:53:33 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/23 12:58:48 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name):
 ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), 
 FragTrap(name + "_scav_name"), name(name) {
  hitPoints = FragTrap::hitPoints;
  energyPoints = ScavTrap::energyPoints;
  attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
 ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
  hitPoints = other.hitPoints;
  energyPoints = other.energyPoints;
  attackDamage = other.attackDamage;
  std::cout << "Another wild DiamondTrap " << name << " appears!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    ScavTrap::operator=(other);
    FragTrap::operator=(other);
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "One more DiamondTrap " << name << " appears!" << std::endl;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << name << " finds that diamonds aren't eternal..." << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
  std::cout << "Who am I? I'm " << ClapTrap::name 
  << " but also: " << name << std::endl;
}

const std::string DiamondTrap::getName() const {
  return name;
}

unsigned int DiamondTrap::getHitPoints() const {
  return hitPoints;
}

unsigned int DiamondTrap::getEnergyPoints() const {
  return energyPoints;
}

unsigned int DiamondTrap::getAttackDamage() const {
  return attackDamage;
}
