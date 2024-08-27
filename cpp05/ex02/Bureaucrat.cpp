/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:45:56 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 20:51:53 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat():
  name("Forsaken Minion"), grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name):
  name(name), grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade): name(name) {
  validateGrade(grade).setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
  name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    grade = other.grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
  return name;
}

int Bureaucrat::getGrade() const {
  return grade;
}

Bureaucrat& Bureaucrat::incrementGrade(int increment) {
  int newGrade = grade - increment;
  validateGrade(newGrade).setGrade(newGrade);
  return *this;
}

Bureaucrat& Bureaucrat::decrementGrade(int decrement) {
  int newGrade = grade + decrement;
  validateGrade(newGrade).setGrade(newGrade);
  return *this;
}

Bureaucrat& Bureaucrat::validateGrade(int grade) {
  if (grade > LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  if (grade < HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
  return *this;
}

Bureaucrat& Bureaucrat::setGrade(int newGrade) {
  grade = newGrade;
  return *this;
}

void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    PRINT(L_GREEN, getName() + " signed " + form.getName());
  } catch (std::exception& exception) {
    CERR(RED, getName() + " couldn't sign " + form.getName() + " because ");
    PERR(BOLD BLACK BG_RED, exception.what());
  }
}

void Bureaucrat::executeForm(AForm& form) {
  try {
    form.beExecuted(*this);
  } catch (std::exception& exception) {
    CERR(RED, getName() + " couldn't execute " + form.getSpec() + " because ");
    PERR(BOLD BLACK BG_RED, exception.what());
  }
}

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat) {
  ostream << bureaucrat.getName() 
          << ", bureaucrat grade " 
          << bureaucrat.getGrade() 
          << ".";
  return ostream;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Exception - Bureaucrat: Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Exception - Bureaucrat: Grade too Low";
}
