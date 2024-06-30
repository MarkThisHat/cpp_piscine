/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:07:13 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 20:08:12 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class IMateriaSource {
 public:
  virtual ~IMateriaSource();
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(const std::string& type) = 0;
};
