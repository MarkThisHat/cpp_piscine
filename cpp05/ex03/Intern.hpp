/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:18:13 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/26 23:22:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern {
  public:
   Intern();
   Intern(const Intern& other);
   Intern& operator=(const Intern& other);
   ~Intern();

   Form* makeForm(const std::string formName, const std::string formTarget);
};
