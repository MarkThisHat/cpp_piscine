/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:02:30 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/03 20:21:27 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Floor {
 public:
  static Floor& getInstance();
  void addMateria(AMateria* materia);
  void clearMaterias();

 private:
  struct MateriaNode {
    AMateria* materia;
    MateriaNode* next;
  };
  MateriaNode *head;

  Floor();
  Floor(const Floor& other);
  Floor& operator=(const Floor& other);
  ~Floor();
};
