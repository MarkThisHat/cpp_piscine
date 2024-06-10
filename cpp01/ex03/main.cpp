/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 13:04:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
  Weapon bobClub = Weapon("crude spiked club");
  HumanA bob("Bob", bobClub);
  bob.attack();
  bobClub.setType("some other type of club");
  bob.attack();

  Weapon jimClub = Weapon("crude spiked club");
  HumanB jim("Jim");
  jim.setWeapon(jimClub);
  jim.attack();
  jimClub.setType("some other type of club");
  jim.attack();
  jim.unsetWeapon();
  jim.attack();

  return 0;
}
