/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:34:45 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/25 09:35:10 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Form {
 public:
  Form();
  Form(const std::string name, const int gradeToSign, const int gradeToExec);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

 private:
  const std::string name;
  const int gradeToSign;
  const int gradeToExec;
  bool isSigned;

  Form& allowSignature(const Bureaucrat& candidate);
  Form& allowExecution(const Bureaucrat& candidate);
  Form& beSigned(const Bureaucrat& signer);

  class GradeTooHighException: public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException: public std::exception {
   public:
    const char* what() const throw();
  };

};

std::ostream& operator<<(std::ostream& ostream, const Form& form);