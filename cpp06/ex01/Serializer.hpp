/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:08:56 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/02 13:58:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include "Data.hpp"

class Serializer {
 private:
  Serializer();
  ~Serializer();
  Serializer(const Serializer&);
  Serializer& operator=(const Serializer&);

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};
