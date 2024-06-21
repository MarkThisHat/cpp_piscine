/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:28:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/21 14:46:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  ClapTrap claptrap1("CT-01");
  claptrap1.attack("Target-01");
  claptrap1.attack("Target-02");

  claptrap1.takeDamage(5);

  claptrap1.beRepaired(3);
  claptrap1.beRepaired(8);

  for (int i = 0; i < 10; ++i) {
      claptrap1.attack("Target-03");
  }

  claptrap1.attack("Target-04");
  claptrap1.beRepaired(5);

  ClapTrap claptrap2(claptrap1);
  claptrap2.attack("Target-05");

  ClapTrap claptrap3("CT-03");
  claptrap3 = claptrap1;
  claptrap3.attack("Target-06");

  return 0;
}
