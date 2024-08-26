/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:34:45 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 11:26:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>

class Bureaucrat;

class Form {
 public:
  Form();
  Form(const std::string name, const int gradeToSign, const int gradeToExec);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

  const std::string getName() const;
  int getGradeToSign() const;
  int getGradeToExec() const;
  bool getIsSigned() const;
  Form& validateGrade(int grade);
  Form& beSigned(const Bureaucrat& signer);

 private:
  const std::string name;
  const int gradeToSign;
  const int gradeToExec;
  bool isSigned;


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