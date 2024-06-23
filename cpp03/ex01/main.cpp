/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:28:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/26 15:36:33 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
  ScavTrap scavtrap("ST-01");
  scavtrap.guardGate();
  scavtrap.guardGate();
  scavtrap.guardGate();
  scavtrap.attack("Target-01");
  scavtrap.attack("Target-02");

  scavtrap.takeDamage(5);

  scavtrap.beRepaired(3);
  scavtrap.beRepaired(8);


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
  ClapTrap* ptr = new ScavTrap("ST-02");
  ptr->attack("proof why you should use virtual attack");
  // Incorrect cleanup if destructor is not virtual
  delete ptr;
  return 0;
}
