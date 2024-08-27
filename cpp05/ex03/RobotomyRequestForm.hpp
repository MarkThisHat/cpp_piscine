/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
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
#include <cstdlib>
#include <ctime>

#define ROBOTOMY_SIGN_GRADE 72
#define ROBOTOMY_EXEC_GRADE 45

class RobotomyRequestForm: public AForm {
 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();

  std::string getSpec() const;
  AForm& beExecuted(const Bureaucrat& executor);

 private:
  bool rollFiftyFifty() const;
};
