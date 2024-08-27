/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:26:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 23:08:09 by maalexan         ###   ########.fr       */
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
  Form* pardon = new PresidentialPardonForm(pardonArg);
  PRINT(PINK, *pardon);
  minion.executeForm(*pardon);
  boss.executeForm(*pardon);
  boss.signForm(*pardon).executeForm(*pardon);
  PRINT(PINK, *pardon);
  endTest();
  delete pardon;

  const std::string shrubArg = argc > 2 ? argv[2] : "Shrub-Target";
  Form* shrubbery = new ShrubberyCreationForm(shrubArg);
  PRINT(PINK, *shrubbery);
  minion.executeForm(*shrubbery);
  boss.executeForm(*shrubbery);
  boss.signForm(*shrubbery).executeForm(*shrubbery);
  PRINT(PINK, *shrubbery);
  endTest();
  delete shrubbery;

  const std::string robotArg = argc > 3 ? argv[3] : "Robot-Target";
  Form* robotomy = new RobotomyRequestForm(robotArg);
  PRINT(PINK, *robotomy);
  minion.executeForm(*robotomy);
  boss.executeForm(*robotomy);
  boss.signForm(*robotomy).executeForm(*robotomy);
  PRINT(PINK, *robotomy);
  endTest();

  bool proveRandom = argc > 4 ? true : false;
  if (proveRandom) for (int i = 0; i < 16; i++) boss.executeForm(*robotomy);
  delete robotomy;
}
