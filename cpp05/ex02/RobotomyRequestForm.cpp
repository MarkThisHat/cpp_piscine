/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:52:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 21:18:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
  :AForm("Default", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE) {
    std::srand(time(0));
  }

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
  :AForm(target, ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE) {
    std::srand(time(0));
  }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  :AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getSpec() const {
  return "Robotomy Request Form with target <" + getName() + ">";
}

AForm& RobotomyRequestForm::beExecuted(const Bureaucrat& executor) {
  if (executor.getGrade() > getGradeToExec()) {
    throw GradeTooLowException();
  }
  if (!getIsSigned()) {
    throw FormNotSignedException();
  }
  COUT(BG_YELLOW BLACK, "Makes some drilling noises ... ");
  (rollFiftyFifty()) ? 
  PRINT(BG_GREEN BLACK BOLD, getName() + " has been robotomized successfuly" ) :
  PRINT(BG_LPINK BLACK BOLD, "The robotomy failed on " + getName());
  return *this;
}

bool RobotomyRequestForm::rollFiftyFifty() const {
  return (std::rand() % 2) == 0;
}
