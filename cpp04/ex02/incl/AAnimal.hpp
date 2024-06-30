/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:08:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 14:19:41 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../ex00/incl/pretty_print.hpp"
#include "Brain.hpp"

class AAnimal {
 public:
  AAnimal();
  AAnimal(const AAnimal& other);
  AAnimal(const std::string& type);
  AAnimal& operator=(const AAnimal& other);
  virtual ~AAnimal();

  const std::string getType() const;
  virtual void makeSound() const = 0;
  virtual const Brain& getBrain() const = 0;
  virtual void setBrainIdea(const std::string& idea, int index) = 0;

 protected:
  std::string type;
};
