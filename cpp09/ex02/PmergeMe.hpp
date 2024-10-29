/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/29 16:52:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

template <template <typename, typename> class Container, typename T, typename Allocator = std::allocator<T> >
class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void mergeInsertionSort(Container<T, Allocator>& container, int containerSize);
  Container<T, Allocator> mergeInsertionSort(const Container<T, Allocator>& container, int containerSize) const;
  void printContainer(const Container<T, Allocator>& container) const;

 private:
  void binary_insert(std::vector<T>& sorted, const T& element);
  std::vector<T> lastRecursion(std::vector<T>& container, int size);
  void distribute(const std::vector<T>& container, std::vector<T>& high, std::vector<T>& low);
  std::vector<T> merge(std::vector<T>& container, int size);
};

#include "PmergeMe.tpp"
