/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:01:55 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 20:04:11 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../ex00/incl/pretty_print.hpp"

class ICharacter;

class AMateria
{
protected:
 std::string type;

 public:
  AMateria(std::string const & type);
  const std::string& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};
