/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:21:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 22:14:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "pretty_print.hpp"

#define PARDON_SIGN_GRADE 25
#define PARDON_EXEC_GRADE 5

class PresidentialPardonForm: public AForm {
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();

  std::string getSpec() const;
  AForm& beExecuted(const Bureaucrat& executor);

 };
