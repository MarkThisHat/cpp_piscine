/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:28:52 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 21:12:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pretty_print.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string& name);
  Bureaucrat(const std::string& name, const int proposedGrade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other); 
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;

  Bureaucrat& incrementGrade(int increment);
  Bureaucrat& decrementGrade(int decrement);

  Bureaucrat& signForm(AForm& form);
  Bureaucrat& executeForm(AForm& form);

 private:
  const std::string name;
  int grade;

  Bureaucrat& validateGrade(int grade);
  Bureaucrat& setGrade(int newGrade);

  class GradeTooHighException: public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException: public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat);
