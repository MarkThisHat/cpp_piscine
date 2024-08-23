/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:28:52 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/22 23:58:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

#include <string>

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string& name);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other); 
  ~Bureaucrat();

  const std::string getName() const;
  const int getGrade() const;

  void incrementGrade(int increment);
  void decrementGrade(int decrement);

 private:
  std::string name;
  int grade;

  void GradeTooHighException() const;
  void GradeTooLowException() const;
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat);
