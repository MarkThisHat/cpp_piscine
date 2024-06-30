/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:06:22 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 15:04:02 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat: public Animal {
 public:
  Cat();
  Cat(const Cat& other);
  Cat& operator=(const Cat& other);
  ~Cat();

  //Cats use a brain pointer because their thinking is more complicated
  const Brain* getBrain() const;
  void setBrainIdea(const std::string& idea, int index);
  void makeSound() const;

 private:
  Brain *brain;
};
