/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:26:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 22:34:02 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void endTest() {
  PRINT(BLACK, "");
}

int main(int argc, char** argv) {
  Bureaucrat minion = Bureaucrat();
  Bureaucrat boss = Bureaucrat("Boss", 2);

  const std::string pardonArg = argc > 1 ? argv[1] : "Felon";
  AForm* pardon = new PresidentialPardonForm(pardonArg);
  PRINT(PINK, *pardon);
  minion.executeForm(*pardon);
  boss.executeForm(*pardon);
  boss.signForm(*pardon).executeForm(*pardon);
  PRINT(PINK, *pardon);
  endTest();
  delete pardon;

  const std::string shrubArg = argc > 2 ? argv[2] : "Shrub-Target";
  AForm* shrubbery = new ShrubberyCreationForm(shrubArg);
  PRINT(PINK, *shrubbery);
  minion.executeForm(*shrubbery);
  boss.executeForm(*shrubbery);
  boss.signForm(*shrubbery).executeForm(*shrubbery);
  PRINT(PINK, *shrubbery);
  endTest();
  delete shrubbery;

  const std::string robotArg = argc > 3 ? argv[3] : "Robot-Target";
  AForm* robotomy = new RobotomyRequestForm(robotArg);
  PRINT(PINK, *robotomy);
  minion.executeForm(*robotomy);
  boss.executeForm(*robotomy);
  boss.signForm(*robotomy).executeForm(*robotomy);
  PRINT(PINK, *robotomy);
  for (int i = 0; i < 10; i++) boss.executeForm(*robotomy);
  endTest();
  delete robotomy;
}
