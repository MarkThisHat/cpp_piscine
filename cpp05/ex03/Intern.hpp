/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:18:13 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/27 17:06:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#define FORM_AMOUNT 3

class Intern {
 public:
  Intern();
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  ~Intern();

  Form* makeForm(const std::string formName, const std::string formTarget);

 private:
  Form* createPresidentialPardonForm(const std::string target);
  Form* createRobotomyRequestForm(const std::string target);
  Form* createShrubberyCreationForm(const std::string target);

  struct FormArchive {
    std::string formName;
    Form* (Intern::*formType)(const std::string);
  };
  
  FormArchive forms[FORM_AMOUNT];
};
