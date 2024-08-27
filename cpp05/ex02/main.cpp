/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:26:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 22:16:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void endTest() {
  PRINT(BLACK, "");
}

int main(int argc, char** argv) {
  Bureaucrat minion = Bureaucrat();
  Bureaucrat boss = Bureaucrat("Boss", 2);

  const std::string shrubArg = argc > 1 ? argv[1] : "Shrub-Target";
  AForm* shrubbery = new ShrubberyCreationForm(shrubArg);
  PRINT(PINK, *shrubbery);
  minion.executeForm(*shrubbery);
  boss.executeForm(*shrubbery);
  boss.signForm(*shrubbery).executeForm(*shrubbery);
  PRINT(PINK, *shrubbery);
  endTest();
  delete shrubbery;

  const std::string robotArg = argc > 2 ? argv[2] : "Robot-Target";
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
