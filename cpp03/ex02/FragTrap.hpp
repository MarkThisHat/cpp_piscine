/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:18:09 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/26 15:43:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ex01/ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
 public:
  FragTrap(const std::string name);
  FragTrap(const FragTrap& other);
  FragTrap& operator=(const FragTrap& other);
  virtual ~FragTrap();

  virtual void attack(const std::string& target);
  void highFivesGuys() const;

 protected:
  void initEnergyPoints();
  void initHitPoints();
  void initAttackDamage();

 private:
  FragTrap();
};
