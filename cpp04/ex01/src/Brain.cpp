/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:57:41 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 14:28:08 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Brain.hpp"

Brain::Brain() {
 LAY_BLUE("Constructor: ");
 PUT_PINK("It has a BRAIN");
}

Brain::Brain(const Brain& other) {
  LAY_WHITE("Copy constructor: ");
  PUT_PINK("Brain");
  for (int i = 0; i < 100; i++) {
    ideas[i] = other.ideas[i];
  }
}

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (int i = 0; i < 100; i++) {
      ideas[i] = other.ideas[i];
    }
    LAY_WHITE("Operator = overload: ");
    PUT_PINK("Brain");
  }
  return *this;
}

Brain::~Brain() {
  LAY_RED("Destructor: ");
  PUT_PINK("Brainless now");
}
