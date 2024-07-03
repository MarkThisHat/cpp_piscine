/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:10:40 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/03 20:27:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Floor.hpp"

Floor& Floor::getInstance() {
  static Floor instance;
  return instance;
}

Floor::~Floor() {
  clearMaterias();
}

void Floor::addMateria(AMateria* materia) {
  MateriaNode* newNode = new MateriaNode();
  newNode->materia = materia;
  newNode->next = head;
  head = newNode;
}

void Floor::clearMaterias() {
  MateriaNode* current = head;
  while (current != NULL) {
    MateriaNode* toDelete = current;
    current = current->next;
    delete toDelete->materia;
    delete toDelete;
  }
  head = NULL;
}

Floor::Floor(): head(NULL) {}
Floor::Floor(const Floor& other) {(void)other;}
Floor& Floor::operator=(const Floor& other) {(void)other; return *this;}
