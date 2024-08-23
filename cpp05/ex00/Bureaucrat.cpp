/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:45:56 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/23 11:48:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
  name("Forsaken Minion"), grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name):
  name(name), grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade): name(name) {
  validate(grade).setGrade(grade);
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

const std::string Bureaucrat::getName() const {
  return name;
}

int Bureaucrat::getGrade() const {
  return grade;
}

Bureaucrat &Bureaucrat::incrementGrade(int increment) {
  int newGrade = grade - increment;
  validate(newGrade).setGrade(newGrade);
  return *this;
}

Bureaucrat &Bureaucrat::decrementGrade(int decrement) {
  int newGrade = grade + decrement;
  validate(newGrade).setGrade(newGrade);
  return *this;
}

Bureaucrat& Bureaucrat::validate(int grade) {
  if (grade > LOWEST_GRADE) {
    throw GradeTooLowException();
  }
  if (grade < HIGHEST_GRADE) {
    throw GradeTooHighException();
  }
  return *this;
}

Bureaucrat& Bureaucrat::setGrade(int grade) {
  grade = grade;
  return *this;
}

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat) {
  ostream << bureaucrat.getName() 
          << ", bureaucrat grade " 
          << bureaucrat.getGrade() 
          << ".";
  return ostream;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too Low";
}
