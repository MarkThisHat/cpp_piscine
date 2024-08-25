/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:27:59 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/25 09:38:00 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
  name("Useless Form"),
  gradeToSign(LOWEST_GRADE),
  gradeToExec(LOWEST_GRADE),
  isSigned(false) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec):
  name(name),
  gradeToSign(gradeToSign),
  gradeToExec(gradeToExec),
  isSigned(false) {}

Form::Form(const Form &other):
  name(other.name),
  gradeToSign(other.gradeToSign),
  gradeToExec(other.gradeToExec),
  isSigned(other.isSigned){}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    isSigned = other.isSigned;
  }
  return *this;
}

Form::~Form(){}


const char* Form::GradeTooHighException::what() const throw() {
  return "Exception - Form: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Exception - Form: Grade too Low";
}