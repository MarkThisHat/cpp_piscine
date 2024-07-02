/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:47:33 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/02 19:50:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../incl/AMateria.hpp"

class Ice: public AMateria {
 public:
  Ice(const std::string& type);
  Ice(const Ice& other);
  Ice& operator=(const Ice& other);
  ~Ice();

  const std::string& getType() const;
  AMateria* clone() const;
  void use(ICharacter& target);

 private:
  Ice();
};
