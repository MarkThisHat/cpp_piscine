/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:34:31 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/23 12:18:25 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
  DiamondTrap dt("Diamond");

  dt.attack("target");
  dt.whoAmI();

  std::cout << "Hit points: " << dt.getHitPoints() << std::endl;
  std::cout << "Energy points: " << dt.getEnergyPoints() << std::endl;
  std::cout << "Attack damage: " << dt.getAttackDamage() << std::endl;

  return 0;
}
