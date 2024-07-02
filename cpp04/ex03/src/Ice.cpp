/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:53:26 by maalexan          #+#    #+#             */
/*   Updated: 2024/07/02 20:25:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria(other.type) {}

Ice& Ice::operator=(const Ice& other) {
  if (this != &other) {
    type = "ice";
  }
  return *this;
}

Ice::~Ice() {};