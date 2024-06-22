/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:28:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/22 20:05:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
  FragTrap fragtrap("ST-01");
  fragtrap.attack("Target-01");
  fragtrap.attack("Target-02");

  fragtrap.takeDamage(5);

  fragtrap.beRepaired(3);
  fragtrap.beRepaired(8);

  fragtrap.highFivesGuys();

  for (int i = 0; i < 10; ++i) {
      fragtrap.attack("Target-03");
  }

  fragtrap.attack("Target-04");
  fragtrap.beRepaired(5);

  FragTrap FragTrap2(fragtrap);
  FragTrap2.attack("Target-05");

  FragTrap FragTrap3("ST-03");
  FragTrap3 = fragtrap;
  FragTrap3.attack("Target-06");

  fragtrap.takeDamage(100);
  fragtrap.takeDamage(100);
  fragtrap.attack("Bogus target");
  ClapTrap* ptr = new FragTrap("ST-02");
  ptr->attack("proof why you should use virtual attack");
  // Incorrect cleanup if destructor is not virtual
  delete ptr;
  return 0;
}
