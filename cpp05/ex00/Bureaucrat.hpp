/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:28:52 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/22 19:09:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other); 
  ~Bureaucrat();

  const std::string getName() const;
  const int getGrade() const;
  void incrementGrade(int increment);
  void decrementGrade(int decrement);

 private:
  const std::string name;
  int grade;
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat);
