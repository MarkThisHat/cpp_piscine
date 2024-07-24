/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Limbo.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:02:30 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/06 13:24:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Limbo {
 public:
  static Limbo& getInstance();
  void addMateria(AMateria* materia);
  bool doesNotContain(AMateria* materia) const;
  void clearMaterias();

 private:
  struct MateriaNode {
    AMateria* materia;
    MateriaNode* next;
  };
  MateriaNode *head;

  Limbo();
  Limbo(const Limbo& other);
  Limbo& operator=(const Limbo& other);
  ~Limbo();
};
