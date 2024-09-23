/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:30:03 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/23 10:50:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include "Array.hpp" //this line is mostly for IDE and should be removable

template<typename T>
Array<T>::Array(): data(NULL), members(0) {}

template<typename T>
Array<T>::Array(unsigned int n): data(new T[n]()), members(n) {}

template<typename T>
Array<T>::~Array() {
  delete[] data;
}

template<typename T>
Array<T>::Array(const Array<T>& other):
 data(new T[other.members](), members(other.members)) {
  for (unsigned int i = 0; i < members; i++) {
    data[i] = other.data[i];
  }
 }
 
 template<typename T>
 Array<T>& Array<T>::operator=(const Array<T>& other) {
  if (this != &other) {
    delete[] data;
    members = other.members;
    data = new T[members];
    for (unsigned int i = 0; i < members; i++) {
      data[i] = other.data[i];
    }
  }
  return *this;
 }
 
 template<typename T>
 unsigned int Array<T>::size() const {
  return members;
 }

 template<typename T>
 T& Array<T>::operator[](unsigned int index) {
  if (index < members) {
    return data[index];
  }
  throw std::out_of_range("Invalid index");
 }

template<typename T>
 const T& Array<T>::operator[](unsigned int index) const {
  if (index < members) {
    return data[index];
  }
  throw std::out_of_range("Invalid index");
 }