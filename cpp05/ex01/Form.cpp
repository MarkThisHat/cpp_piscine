/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:27:59 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 13:59:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():
  name("Administrative Form"),
  gradeToSign(LOWEST_GRADE),
  gradeToExec(LOWEST_GRADE),
  isSigned(false) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec):
  name(name),
  gradeToSign(gradeToSign),
  gradeToExec(gradeToExec),
  isSigned(false) {
    validateGrade(gradeToSign).validateGrade(gradeToExec);
  }

Form::Form(const Form& other):
  name(other.name),
  gradeToSign(other.gradeToSign),
  gradeToExec(other.gradeToExec),
  isSigned(other.isSigned){}

Form &Form::operator=(const Form& other) {
  if (this != &other) {
    isSigned = other.isSigned;
  }
  return *this;
}

Form::~Form(){}

const std::string Form::getName() const {
  return name;
}

int Form::getGradeToSign() const {
  return gradeToSign;
}

int Form::getGradeToExec() const {
  return gradeToExec;
}

bool Form::getIsSigned() const {
  return isSigned;
}

Form& Form::validateGrade(int grade) {
  if (grade > LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  if (grade < HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
  return *this;
}

Form& Form::beSigned(const Bureaucrat& signer) {
  if (signer.getGrade() > gradeToSign) {
    throw GradeTooLowException();
  }
  isSigned = true;
  return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Exception - Form: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Exception - Form: Grade too Low";
}

std::ostream &operator<<(std::ostream &ostream, const Form &form) {
  ostream << "Form " << form.getName() << " is "
          << (form.getIsSigned() ? "" : "NOT ") << "signed. It "
          << "requires grade " << form.getGradeToSign() << " to be signed "
          << "and grade " << form.getGradeToExec() << " to be executed.";
  return ostream;  
}
