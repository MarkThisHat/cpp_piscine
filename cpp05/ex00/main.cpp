/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:26:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/23 23:10:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void endTest() {
  PRINT(BLACK, "");
}

void createBureaucrat(const std::string name, int grade) {
  COUT(YELLOW, "Attempting to create Bureaucrat " + name + " with grade ");
  PRINT(BG_GREEN L_WHITE, grade);
  try {
    Bureaucrat bureaucrat = Bureaucrat(name, grade);
    PRINT(L_BLACK BG_YELLOW, "ok");
  } catch (std::exception& exception) {
    PERR(BOLD BLACK BG_RED, exception.what());
  }
  endTest();
}

void promoteBureaucrat(Bureaucrat& bureaucrat, int increase) {
  COUT(L_BLUE, bureaucrat);
  COUT(L_GREEN, " - their rank will try to be increased by ");
  PRINT(L_GREEN, increase);
  try {
    bureaucrat.incrementGrade(increase);
  } catch (std::exception& exception) {
    PERR(BOLD BLACK BG_RED, exception.what());
  }
  PRINT(BLACK BG_GREEN, bureaucrat);
  endTest();
}

void demoteBureaucrat(Bureaucrat& bureaucrat, int decrease) {
  COUT(L_BLUE, bureaucrat);
  COUT(L_PINK, " - their rank will try to be decreased by ");
  PRINT(L_PINK, decrease);
  try {
    bureaucrat.decrementGrade(decrease);
  } catch (std::exception& exception) {
    PERR(BOLD BLACK BG_RED, exception.what());
  }
  PRINT(BLACK BG_PINK, bureaucrat);
  endTest();
}

int main() {
  Bureaucrat minion = Bureaucrat();
  promoteBureaucrat(minion, 100);
  demoteBureaucrat(minion, 50);

  Bureaucrat boss = Bureaucrat("Boss", 1);
  promoteBureaucrat(boss, 1);
  demoteBureaucrat(boss, 150);
  
  createBureaucrat("Dave", 1);
  createBureaucrat("Pave", 150);
  createBureaucrat("Mave", 75);
  createBureaucrat("Save", 0);
  createBureaucrat("Nave", 151);
}
