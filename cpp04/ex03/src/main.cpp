/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:56:52 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/03 20:31:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Character.hpp"
#include "../incl/Cure.hpp"
#include "../incl/Ice.hpp"
#include "../incl/MateriaSource.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  me->use(2, *bob);
  me->use(3, *bob);
  me->unequip(2);
  me->unequip(3);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  me->use(2, *bob);
  me->use(3, *bob);
  for (int i = 0; i < 4; i++) {
    me->unequip(i);
  }
  delete bob;
  delete me;
  delete src;
  return 0;
}
