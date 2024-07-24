/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Limbo.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:10:40 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/06 13:24:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Limbo.hpp"

Limbo& Limbo::getInstance() {
  static Limbo instance;
  return instance;
}

Limbo::~Limbo() {
  clearMaterias();
}

void Limbo::addMateria(AMateria* materia) {
  MateriaNode* newNode = new MateriaNode();
  newNode->materia = materia;
  newNode->next = head;
  head = newNode;
}

bool Limbo::doesNotContain(AMateria* materia) const {
    MateriaNode* current = head;
    while (current != NULL) {
        if (current->materia == materia) return false;
        current = current->next;
    }
    return true;
}

void Limbo::clearMaterias() {
  MateriaNode* current = head;
  while (current != NULL) {
    MateriaNode* toDelete = current;
    current = current->next;
    delete toDelete->materia;
    delete toDelete;
  }
  head = NULL;
}

Limbo::Limbo(): head(NULL) {}
Limbo::Limbo(const Limbo& other) {(void)other;}
Limbo& Limbo::operator=(const Limbo& other) {(void)other; return *this;}
