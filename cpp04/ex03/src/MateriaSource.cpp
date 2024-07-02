/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:57:43 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/02 18:40:35 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < MAX_SLOT; i++) {
    materias[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  copyMaterias(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  if (this != &other) {
    deleteMaterias();
    copyMaterias(other);
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  deleteMaterias();
}

void MateriaSource::copyMaterias(const MateriaSource& other) {
  for (int i = 0; i < MAX_SLOT; i++) {
    materias[i] = (other.materias[i] != NULL) ? other.materias[i]->clone() : NULL;
  }
}

void MateriaSource::deleteMaterias() {
  for (int i = 0; i < MAX_SLOT; i++) {
    if (materias[i] != NULL) {
      delete materias[i];
      materias[i] = NULL;
    }
  }
}

void MateriaSource::learnMateria(AMateria* materia) {
 for (int i = 0; i < MAX_SLOT; i++) {
  if (materias[i] == NULL) {
    materias[i] = materia->clone();
    return;
  }
 }
}

AMateria* createMateria(const std::string& type) {
  for (int i = 0; i < MAX_SLOT; i++) {
    if (materias[i] != NULL && materias[i]->getType() == type) {
      return materias[i]->clone();
    }
  }
  return NULL;
}
