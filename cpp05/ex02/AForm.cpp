/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:27:59 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 13:59:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():
  name("Administrative Form"),
  gradeToSign(LOWEST_GRADE),
  gradeToExec(LOWEST_GRADE),
  isSigned(false) {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec):
  name(name),
  gradeToSign(gradeToSign),
  gradeToExec(gradeToExec),
  isSigned(false) {
    validateGrade(gradeToSign).validateGrade(gradeToExec);
  }

AForm::AForm(const AForm& other):
  name(other.name),
  gradeToSign(other.gradeToSign),
  gradeToExec(other.gradeToExec),
  isSigned(other.isSigned){}

AForm &AForm::operator=(const AForm& other) {
  if (this != &other) {
    isSigned = other.isSigned;
  }
  return *this;
}

AForm::~AForm(){}

const std::string AForm::getName() const {
  return name;
}

int AForm::getGradeToSign() const {
  return gradeToSign;
}

int AForm::getGradeToExec() const {
  return gradeToExec;
}

bool AForm::getIsSigned() const {
  return isSigned;
}

AForm& AForm::validateGrade(int grade) {
  if (grade > LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  if (grade < HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
  return *this;
}

AForm& AForm::beSigned(const Bureaucrat& signer) {
  if (signer.getGrade() > gradeToSign) {
    throw GradeTooLowException();
  }
  isSigned = true;
  return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Exception - AForm: Grade too High";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Exception - AForm: Grade too Low";
}

std::ostream &operator<<(std::ostream &ostream, const AForm &AForm) {
  ostream << "Form " << AForm.getName() << " is "
          << (AForm.getIsSigned() ? "" : "NOT ") << "signed. It "
          << "requires grade " << AForm.getGradeToSign() << " to be signed "
          << "and grade " << AForm.getGradeToExec() << " to be executed.";
  return ostream;  
}
