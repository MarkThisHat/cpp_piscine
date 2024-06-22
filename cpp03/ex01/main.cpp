/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:28:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/22 14:05:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
  ScavTrap scavtrap("ST-01");
  scavtrap.attack("Target-01");
  scavtrap.attack("Target-02");

  scavtrap.takeDamage(5);

  scavtrap.beRepaired(3);
  scavtrap.beRepaired(8);

  scavtrap.guardGate();

  for (int i = 0; i < 10; ++i) {
      scavtrap.attack("Target-03");
  }

  scavtrap.attack("Target-04");
  scavtrap.beRepaired(5);

  ScavTrap ScavTrap2(scavtrap);
  ScavTrap2.attack("Target-05");

  ScavTrap ScavTrap3("ST-03");
  ScavTrap3 = scavtrap;
  ScavTrap3.attack("Target-06");

  scavtrap.takeDamage(100);
  scavtrap.takeDamage(100);
  scavtrap.attack("Bogus target");
  return 0;
}
