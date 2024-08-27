/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:52:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 21:18:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
  :AForm("Default", SHRUBBERY_SIGN_GRADE, SHRUBBRRY_EXEC_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
  :AForm(target, SHRUBBERY_SIGN_GRADE, SHRUBBRRY_EXEC_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
  :AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getSpec() const {
  return "Shrubbery Form with target <" + getName() + ">";
}

AForm& ShrubberyCreationForm::beExecuted(const Bureaucrat& executor) {
  if (executor.getGrade() > getGradeToExec()) {
    throw GradeTooLowException();
  }
  if (!getIsSigned()) {
    throw FormNotSignedException();
  }
  if (writeToFile(getName() + "_shrubbery")) {
    PRINT(GREEN,  getSpec() + " executed successfuly");
  }
  return *this;
}

bool ShrubberyCreationForm::writeToFile(const std::string fileName) {
  std::ofstream outFile(fileName.c_str());
  if (!outFile) {
    PERR(RED, "Failed to open or write to file");
    return false;
  }
  outFile << SHRUBERRY_TREE_A << std::endl;
  outFile << SHRUBERRY_TREE_B << std::endl;
  outFile.close();
  return true;
}
