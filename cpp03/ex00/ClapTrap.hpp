/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:03:59 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/20 21:25:36 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap(const std::string name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap &other);
  ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  std::string name;
  bool active;
  unsigned int hitPoints;
  unsigned int energyPoints;
  unsigned int attackDamage;
  ClapTrap();
};