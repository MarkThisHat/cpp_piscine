/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:04:48 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 20:05:43 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class ICharacter
{
 public:
  virtual ~ICharacter() {}
  virtual const std::string& getName() const = 0;
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int index) = 0;
  virtual void use(int index, ICharacter& target) = 0;
};