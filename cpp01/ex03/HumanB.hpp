/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:08:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 11:41:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {
 public:
  HumanB(std::string name);
  HumanB(std::string name, Weapon& weapon);
  ~HumanB();
  void attack() const;
  std::string getName() const;
  void setWeapon(Weapon& weapon);
  void unsetWeapon();

 private:
  HumanB();
  std::string name_;
  Weapon* weapon_;
};
