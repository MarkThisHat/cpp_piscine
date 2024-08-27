/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:21:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 22:03:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "pretty_print.hpp"
#include <fstream>

#define SHRUBBERY_SIGN_GRADE 145
#define SHRUBBERRY_EXEC_GRADE 137

class ShrubberyCreationForm: public AForm {
 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm();

  std::string getSpec() const;
  AForm& beExecuted(const Bureaucrat& executor);

 private:
  bool writeToFile(const std::string fileName);
};
