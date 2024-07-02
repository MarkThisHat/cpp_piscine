/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:47:33 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/02 20:42:10 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../incl/AMateria.hpp"
#include "../incl/ICharacter.hpp"

class Cure: public AMateria {
 public:
  Cure();
  Cure(const Cure& other);
  Cure& operator=(const Cure& other);
  ~Cure();

  const std::string& getType() const;
  AMateria* clone() const;
  void use(ICharacter& target);
};
