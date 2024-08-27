/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:21:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 23:24:10 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other){}

Intern& Intern::operator=(const Intern& other) {
  return *this;
}

Intern::~Intern() {}

Form *Intern::makeForm(const std::string formName, const std::string formTarget) {
  return nullptr;
}
