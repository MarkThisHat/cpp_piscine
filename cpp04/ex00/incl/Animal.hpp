/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:08:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/29 12:31:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "pretty_print.hpp"
#include <string>

class Animal {
 public:
  Animal();
  Animal(const Animal& other);
  Animal& operator=(const Animal& other);
  virtual ~Animal();

  const std::string getType() const;
  virtual void makeSound() const;

 protected:
  std::string type;
};
