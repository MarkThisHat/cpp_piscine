/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:52:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 21:18:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
  :AForm("Default", PARDON_SIGN_GRADE, PARDON_EXEC_GRADE) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
  :AForm(target, PARDON_SIGN_GRADE, PARDON_EXEC_GRADE) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
  :AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getSpec() const {
  return "Presidential Pardon Form with target <" + getName() + ">";
}

AForm& PresidentialPardonForm::beExecuted(const Bureaucrat& executor) {
  validateExecution(executor);
  PRINT(YELLOW UNDERLINE, getName() + " has been pardoned by Zaphod Beeblebrox" );
  return *this;
}
