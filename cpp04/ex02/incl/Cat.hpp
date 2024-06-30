/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:06:22 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 16:09:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"

class Cat: public AAnimal {
 public:
  Cat();
  Cat(const Cat& other);
  Cat& operator=(const Cat& other);
  ~Cat();

  const Brain& getBrain() const;
  void setBrainIdea(const std::string& idea, int index);
  void makeSound() const;

 private:
  Brain *brain;
};
