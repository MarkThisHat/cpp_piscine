/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:44:57 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/22 20:04:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name): ClapTrap(name) {
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "A wild FragTrap " << name << " appears!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
  std::cout << "Another wild FragTrap " << name << " appears!" << std::endl;       
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    std::cout << "Yet another FragTrap " << name << " appears!" << std::endl;
  }
  return *this;
}

void FragTrap::attack(const std::string& target) {
  std::cout << "FragTrap " << name;
  if (!hitPoints || !spendEnergy(1)) {
    std::cout << " is unable to attack!";
  } else {
    std::cout << " attacks " << target << " for [" << attackDamage
      << (attackDamage > 0 ? "] damage! (" : "] - no harm done! (")
      << energyPoints << ") energy points left.";
  }
  std::cout << std::endl;
}

void FragTrap::highFivesGuys() const {
    std::cout << "FragTrap " << name 
      << " is requesting a high five! High fives, folks!" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << name 
    << " holds up its hand waiting for a final high five..." << std::endl;
}
