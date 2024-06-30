/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
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

class Animal {
 public:
  Animal();
  Animal(const Animal& other);
  Animal(const std::string& type);
  Animal& operator=(const Animal& other);
  virtual ~Animal();

  const std::string getType() const;
  virtual void makeSound() const;

 protected:
  std::string type;
};
