/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:47:33 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/02 20:43:41 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../incl/AMateria.hpp"
#include "../incl/ICharacter.hpp"

class Ice: public AMateria {
 public:
  Ice();
  Ice(const Ice& other);
  Ice& operator=(const Ice& other);
  ~Ice();

  const std::string& getType() const;
  AMateria* clone() const;
  void use(ICharacter& target);
};
