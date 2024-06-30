/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:34:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 14:49:30 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../ex00/incl/pretty_print.hpp"
#include <string>

class Brain {
 public:
  Brain();
  Brain(const Brain& other);
  Brain& operator=(const Brain& other);
  ~Brain();

  const std::string& getIdea(int index) const;
  void setIdea(const std::string& idea, int index);

 private:
  std::string ideas[100];
};