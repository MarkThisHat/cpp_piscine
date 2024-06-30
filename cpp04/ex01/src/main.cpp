/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:10 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 13:50:53 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

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
  return 0;
}
