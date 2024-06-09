/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:14:29 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/09 16:07:43 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
 public:
  Weapon(const std::string& type);
  ~Weapon();
  const std::string& getType() const;
  void setType(const std::string& type);

 private:
  Weapon();
  std::string type_;
};
