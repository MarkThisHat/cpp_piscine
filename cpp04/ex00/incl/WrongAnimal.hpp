/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:28:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 16:51:23 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "pretty_print.hpp"

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& other);
  WrongAnimal(const std::string& type);
  WrongAnimal& operator=(const WrongAnimal& other);
  virtual ~WrongAnimal();

  const std::string getType() const;
  void makeSound() const;

 protected:
  std::string type;
};
