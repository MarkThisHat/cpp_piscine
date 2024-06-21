/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:11:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/21 15:00:16 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name): name(name),
 hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "A wild ClapTrap " << name << " appears!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): name(other.name),
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
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  std::cout << "ClapTrap " << name;
  if (!hitPoints || !spendEnergy(1)) {
    std::cout << " is unable to attack!";
  } else {
    std::cout << " attacks " << target << " for [" << attackDamage
      << (attackDamage > 0 ? "] damage! (" : "] - no harm done! (")
      << energyPoints << ") energy points left).";
  }
  std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  unsigned int damage = (amount < hitPoints) ? amount : hitPoints;
  std::cout << "ClapTrap " << name << " takes " 
    << (damage > 0 ? "[" : "no [") << damage << "] damage!" << std::endl;
  hitPoints -= damage;
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "ClapTrap " << name;
  if (!amount || !hitPoints || !spendEnergy(1)) {
    std:: cout << " is unable to repair itself!";
  } else {
    std::cout << " repairs [" << amount << "] damage! ("
      << energyPoints << ") energy points left).";
    hitPoints += amount;
  }
  std::cout << std::endl;
}

const std::string ClapTrap::getName() const {
  return name;
}

unsigned int ClapTrap::getHitPoints() const {
  return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
  return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
  return attackDamage;
}

bool ClapTrap::spendEnergy(unsigned int amount) {
  if (!amount || energyPoints < amount) {
    return false;
  }
  energyPoints -= amount;
  return true;
}
