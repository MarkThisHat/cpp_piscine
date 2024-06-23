/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:53:33 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/23 12:19:40 by maalexan         ###   ########.fr       */
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
 ClapTrap(other), ScavTrap(other), FragTrap(other) {
  std::cout << "Another wild DiamondTrap " << name << " appears!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  if (this != &other) {
    DiamondTrap::operator=(other);
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
