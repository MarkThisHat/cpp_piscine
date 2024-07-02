/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:07:13 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/02 16:56:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../ex00/incl/pretty_print.hpp"

class AMateria;

class IMateriaSource {
 public:
  IMateriaSource();
  IMateriaSource(const IMateriaSource& other);
  IMateriaSource& operator=(const IMateriaSource& other);
  virtual ~IMateriaSource();
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(const std::string& type) = 0;
};
