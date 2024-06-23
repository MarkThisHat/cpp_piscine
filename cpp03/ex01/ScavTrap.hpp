/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:18:09 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/26 15:19:33 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
 public:
  ScavTrap(const std::string name);
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& other);
  virtual ~ScavTrap();

  void guardGate();
  bool guardingStatus() const;

  virtual void attack(const std::string& target);

 protected:
  void initEnergyPoints();
  void initHitPoints();
  void initAttackDamage();

 private:
  bool guarding;
  ScavTrap();
};
