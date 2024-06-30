/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:28:10 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 15:22:13 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"
#include "../incl/Dog.hpp"

int main() {
  Dog dog1;

  dog1.setBrainIdea("Play with owner", 0);
  dog1.setBrainIdea("Bark at mailman", 1);
  dog1.setBrainIdea("Chase motorcycle", 2);
  {
    Dog tmp = dog1;
    Cat cat1;

    cat1.setBrainIdea("Sleep all day", 0);
    tmp.setBrainIdea("Find the cat", 0);
    tmp.setBrainIdea("Run after the cat", 1);
    dog1.setBrainIdea("Play with cat", 2);

    Cat cat2 = cat1;
    Cat cat3;
    cat3 = cat1;

    LAY_WHITE("Cat1's first idea: ");
    PUT_L_YELLOW(cat1.getBrain()->getIdea(0));
    LAY_WHITE("Cat2's first idea: ");
    PUT_L_YELLOW(cat2.getBrain()->getIdea(0));
    LAY_WHITE("Cat3's first idea: ");
    PUT_L_YELLOW(cat3.getBrain()->getIdea(0));

    cat2.setBrainIdea("Murder all humans", 0);

    LAY_WHITE("Cat1's first idea: ");
    PUT_L_YELLOW(cat1.getBrain()->getIdea(0));
    LAY_WHITE("Cat2's first idea: ");
    PUT_L_YELLOW(cat2.getBrain()->getIdea(0));
    LAY_WHITE("Cat3's first idea: ");
    PUT_L_YELLOW(cat3.getBrain()->getIdea(0));

    PUT_WHITE("Tmp's ideas: ");
    for (int i = 0; i < 3; i++) {
      PUT_GREEN(tmp.getBrain().getIdea(i));
    }
  }
  PUT_WHITE("Dog1's ideas: ");
  for (int i = 0; i < 3; i++) {
    PUT_GREEN(dog1.getBrain().getIdea(i));
  }

  return 0;
}