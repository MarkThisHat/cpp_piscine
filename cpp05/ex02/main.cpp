/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:26:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 20:40:05 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void endTest() {
  PRINT(BLACK, "");
}

int main() {
  Bureaucrat minion = Bureaucrat();
  Bureaucrat boss = Bureaucrat("Boss", 2);
  AForm* shrubbery = new ShrubberyCreationForm("pog");
  minion.executeForm(*shrubbery);
  boss.executeForm(*shrubbery);
  delete shrubbery;  
}
