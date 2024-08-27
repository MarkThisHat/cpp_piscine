/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:34:45 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 16:10:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <ostream>

class Bureaucrat;

class AForm {
 public:
  AForm();
  AForm(const std::string name, const int gradeToSign, const int gradeToExec);
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  virtual ~AForm();

  std::string getName() const;
  int getGradeToSign() const;
  int getGradeToExec() const;
  bool getIsSigned() const;
  AForm& validateGrade(int grade);
  AForm& beSigned(const Bureaucrat& signer);

  virtual std::string getSpec() const = 0;
  virtual AForm& beExecuted(const Bureaucrat& executor) = 0;

  class GradeTooHighException: public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException: public std::exception {
   public:
    const char* what() const throw();
  };

  class FormNotSignedException: public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  const std::string name;
  const int gradeToSign;
  const int gradeToExec;
  bool isSigned;
};

std::ostream& operator<<(std::ostream& ostream, const AForm& AForm);