/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:49:30 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/03 18:13:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

class Character: public ICharacter {
 public:
  Character(const std::string name);
  Character(const Character& other);
  Character& operator=(const Character& other);
  ~Character();

  const std::string& getName() const;
  void equip(AMateria* m);
  void unequip(int index);
  void use(int index, ICharacter& target);

 private:
  Character();
  void copyMaterias(const Character& other);
  const std::string name;
  AMateria* materias[MAX_SLOT];
};
