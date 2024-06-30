/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:36:57 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 16:09:43 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"

class Dog : public AAnimal {
 public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  ~Dog();

  const Brain& getBrain() const;
  void setBrainIdea(const std::string& idea, int index);
  void makeSound() const;

 private:
  Brain *brain;
};
