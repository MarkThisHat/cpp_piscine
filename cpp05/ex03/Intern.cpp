/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:21:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/27 17:06:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
  forms[0] = { "presidential pardon", &Intern::createPresidentialPardonForm };
  forms[1] = { "robotomy request", &Intern::createRobotomyRequestForm };
  forms[2] = { "shrubbery creation", &Intern::createShrubberyCreationForm };
}

Intern::Intern(const Intern& other){
  for (int i = 0; i < FORM_AMOUNT; i++) {
    forms[i] = other.forms[i];
  }
}

Intern& Intern::operator=(const Intern& other) {
  if (this != &other) {
    for (int i = 0; i < FORM_AMOUNT; i++) {
      forms[i] = other.forms[i];
    }
  }
  return *this;
}

Intern::~Intern() {}

Form* Intern::makeForm(const std::string formName, const std::string formTarget) {
  for (int i = 0; i < FORM_AMOUNT; i++) {
    if (forms[i].formName == formName)
      return (this->*forms[i].formType)(formTarget);
  }
  PERR(RED BOLD, "Intern was not able to find form " + formName);
  return NULL;
}

Form* Intern::createPresidentialPardonForm(const std::string target) {
  PRINT(YELLOW BOLD, "Intern creates presidential pardon form");
  return new PresidentialPardonForm(target);
}

Form* Intern::createRobotomyRequestForm(const std::string target) {
  PRINT(CYAN BOLD, "Intern creates robotomy request form");
  return new RobotomyRequestForm(target);
}

Form* Intern::createShrubberyCreationForm(const std::string target) {
  PRINT(GREEN BOLD, "Intern creates shrubbery creation form");
  return new ShrubberyCreationForm(target);
}
