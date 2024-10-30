/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/30 15:45:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

#define DEBUG 0
#define PRECISION 2
#define PRINTABLE 15

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
  bool isSorted(const Container<T, Allocator>& container, const std::string containerName) const;

 private:
  std::vector<int> groupSizes;
  void calculateGroupSizes(int n);
  void clockLog(int range, double sortTime) const;
  void clockLog(int range, double sortTime, double transferIn, double transferOut) const;
  double clockCalc(clock_t start, clock_t finish) const;
  void specializedBinaryInsert(std::vector<T>& sorted, const T& element, typename std::vector<T>::iterator end);
  std::vector<T> lastRecursion(std::vector<T>& container, int size);
  void distribute(const std::vector<T>& container, std::vector<T>& high, std::vector<T>& low);
  std::vector<T> merge(std::vector<T>& container, int size);
  void orderedInsertion(std::vector<T>& sorted, std::vector<T>& unsorted);

  void binaryInsert(std::vector<T>& sorted, const T& element);
  void printGroupSizes(int sum) const;
};

#include "PmergeMe.tpp"
