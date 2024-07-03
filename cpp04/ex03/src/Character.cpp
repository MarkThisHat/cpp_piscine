/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:57:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/03 19:52:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Character.hpp"

Character::Character(const std::string name): name(name) {
  for (int i = 0; i < MAX_SLOT; i++) {
    materias[i] = NULL;
  }
}

Character::Character(const Character& other): name(other.name) {
  copyMaterias(other);
}

Character& Character::operator=(const Character& other) {
  if (this != &other) {
    for (int i = 0; i < MAX_SLOT; i++) {
      if (materias[i] != NULL) {
        delete materias[i];
        materias[i] = NULL;
      }
    }
    copyMaterias(other);
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < MAX_SLOT; i++) {
    if (materias[i] != NULL) delete materias[i];
  }
}

void Character::equip(AMateria *m) {
  for (int i = 0; i < MAX_SLOT; i++) {
    if (materias[i] == NULL) {
      materias[i] = m;
      return;
    }
  }
}

void Character::unequip(int index) {
  if (materias[index] == NULL) return;
}

void Character::use(int index, ICharacter& target) {
  if (index >= MAX_SLOT || materias[index] == NULL) return;
  materias[index]->use(target);
}

const std::string& Character::getName() const {
  return name;
}

void Character::copyMaterias(const Character& other) {
  for (int i = 0; i < MAX_SLOT; i++) {
    materias[i] = (other.materias[i] != NULL) ? other.materias[i]->clone() : NULL;
  }
}
