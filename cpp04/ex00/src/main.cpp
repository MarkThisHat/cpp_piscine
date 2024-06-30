/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:10 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 11:21:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
  {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    LAY_L_WHITE("Calling get type for both: ");
    PUT_WHITE(j->getType() + " " + i->getType());
    PUT_L_WHITE("Function makeSound:");
    LAY_L_CYAN("Dog: ");
    i->makeSound();
    LAY_L_CYAN("Cat: ");
    j->makeSound();
    LAY_L_CYAN("Animal: ");
    meta->makeSound();

    delete meta;
    delete i;
    delete j;
  }
  PUT_L_WHITE("\nWRONG ANIMAL TEST SUITE\n");
  {
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    const WrongCat* wrongCat = new WrongCat();
    PUT_L_WHITE("Function makeSound:");
    LAY_L_CYAN("Animal - 'Wrong Animal' pointer: ");
    wrongMeta->makeSound();
    LAY_L_CYAN("Cat - 'Wrong Animal' pointer: ");
    wrongI->makeSound();
    LAY_L_CYAN("Cat - 'Wrong Cat' pointer: ");
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongI;
    delete wrongCat;
  }
  return 0;
}
