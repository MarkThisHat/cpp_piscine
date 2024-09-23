/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:43:17 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/23 10:50:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
class Array {
 public:
  Array();
  Array(unsigned int n);
  ~Array();
  Array(const Array& other);
  Array& operator=(const Array& other);

  unsigned int size() const;

  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;

 private:
  T* data;
  unsigned int members;
};

#include "Array.tpp"