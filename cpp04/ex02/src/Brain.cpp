/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:57:41 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 15:38:25 by maalexan         ###   ########.fr       */
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
    LAY_WHITE("Operator= overload: ");
    PUT_PINK("Brain");
  }
  return *this;
}

Brain::~Brain() {
  LAY_RED("Destructor: ");
  PUT_PINK("Brainless now");
}

const std::string &Brain::getIdea(int index) const {
  static const std::string noIdea = "This animal has no idea";
  if (index < 0 || index > 99 || ideas[index] == "") {
    return noIdea;
  }
  return ideas[index];
}

void Brain::setIdea(const std::string &idea, int index)
{
  if (idea == "" || index < 0 || index > 99) {
    PUT_L_RED("That's not really an idea");
    return;
  }
  ideas[index] = idea;
}
