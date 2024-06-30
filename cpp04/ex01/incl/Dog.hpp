/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:36:57 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 15:04:26 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  ~Dog();

  //Dogs use references because their brains thinking process is simpler
  const Brain& getBrain() const;
  void setBrainIdea(const std::string& idea, int index);
  void makeSound() const;

 private:
  Brain *brain;
};
