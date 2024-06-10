/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:08:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 09:31:22 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(std::string name, Weapon& weapon);
  ~HumanA();
  void attack() const;
  std::string getName() const;
  void setWeapon(Weapon& weapon);

 private:
  HumanA();
  std::string name_;
  Weapon& weapon_;
};
