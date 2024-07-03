/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:01:55 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/03 16:54:06 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../ex00/incl/pretty_print.hpp"

#ifndef NULL
#define NULL 0
#endif
#define MAX_SLOT 4

class ICharacter;

class AMateria {
 public:
  AMateria(const std::string& type);
  AMateria(const AMateria& other);
  AMateria& operator=(const AMateria& other);
  virtual ~AMateria();

  const std::string& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target) = 0;

 protected:
  std::string type;

 private:
  AMateria();
};
