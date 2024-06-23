/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:03:59 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/23 23:16:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap(const std::string name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  virtual ~ClapTrap();

  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  const std::string getName() const;
  unsigned int getHitPoints() const;
  unsigned int getEnergyPoints() const;
  unsigned int getAttackDamage() const;

 protected:
  bool spendEnergy(unsigned int amount);
  std::string name;
  unsigned int hitPoints;
  unsigned int energyPoints;
  unsigned int attackDamage;
  void initEnergyPoints();
  void initHitPoints();
  void initAttackDamage();

 private:
  ClapTrap();
};
