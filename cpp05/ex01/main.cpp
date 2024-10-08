/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:26:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 14:00:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void endTest() {
  PRINT(BLACK, "");
}

Form* createForm(const std::string name, int gradeToSign, int gradeToExec) {
  COUT(CYAN, "Attempting to create Form " + name + " with signeable grade ");
  COUT(CYAN UNDERLINE, gradeToSign);
  COUT(CYAN, " and executable grade ");
  PRINT(CYAN UNDERLINE, gradeToExec);
  Form* newForm = NULL; 

  try {
    newForm = new Form(name, gradeToSign, gradeToExec);
    PRINT(PINK, *newForm);
  } catch (std::exception& exception) {
    PERR(BOLD BLACK BG_RED, exception.what());
  }

  endTest();
  return newForm;
}

int main() {
  Form* invalidForm;
  Bureaucrat minion = Bureaucrat();
  Bureaucrat boss = Bureaucrat("Boss", 2);
  
  invalidForm = createForm("{Invalid high grade}", 0, 1);
  invalidForm = createForm("{Invalid low grade}", 1, 151);
  if (invalidForm != NULL) PRINT(RED, "Invalid form was returned");

  Form* formAnyOne = createForm("{Any one can sign}", 150, 1);
  Form* formNotMinion = createForm("{Minion can't sign}", 149, 1);
  Form* formNoOne = createForm("{No one can sign}", 1, 1);

  PRINT(YELLOW, *formAnyOne);
  minion.signForm(*formAnyOne);
  PRINT(YELLOW, *formAnyOne);
  endTest();
  PRINT(YELLOW, *formNotMinion);
  minion.signForm(*formNotMinion);
  PRINT(YELLOW, *formNotMinion);
  boss.signForm(*formNotMinion);
  PRINT(YELLOW, *formNotMinion);
  endTest();
  PRINT(YELLOW, *formNoOne);
  minion.signForm(*formNoOne);
  PRINT(YELLOW, *formNoOne);
  boss.signForm(*formNoOne);
  PRINT(YELLOW, *formNoOne);
  endTest();
  delete formAnyOne;
  delete formNotMinion;
  delete formNoOne;
}
