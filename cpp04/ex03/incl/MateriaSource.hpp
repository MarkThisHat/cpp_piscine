/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:57:43 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/02 19:46:01 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../incl/IMateriaSource.hpp"

#ifndef NULL
#define NULL 0
#endif
#define MAX_SLOT 4

class MateriaSource: public IMateriaSource {
 public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);
  ~MateriaSource();
  void learnMateria(AMateria* materia);
  AMateria* createMateria(const std::string& type);

  private:
   AMateria* materias[MAX_SLOT];
   void copyMaterias(const MateriaSource& other);
   void deleteMaterias();
};
