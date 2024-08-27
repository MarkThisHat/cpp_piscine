/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:26:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/27 18:42:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Intern.hpp"

void endTest() {
  PRINT(BLACK, "");
}

int main() {
  Bureaucrat boss = Bureaucrat("Boss", 2);
  Intern intern = Intern();
  Form* form;

  form = intern.makeForm("presidential pardon", "A person guilty of thievery");
  boss.signForm(*form);
  boss.executeForm(*form);
  PRINT(PINK, *form);
  delete form;
  endTest();

  form = intern.makeForm("shrubbery creation", "home");
  boss.signForm(*form);
  boss.executeForm(*form);
  PRINT(PINK, *form);
  delete form;
  endTest();

  form = intern.makeForm("robotomy request", "A cyborg wannabe");
  boss.signForm(*form);
  boss.executeForm(*form);
  PRINT(PINK, *form);
  delete form;
  endTest();

  form = intern.makeForm("world peace", "A wishful thinker");
  endTest();
}
