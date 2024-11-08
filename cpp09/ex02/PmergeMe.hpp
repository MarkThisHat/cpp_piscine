/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/11/07 18:48:28 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

# ifndef DEBUG
#  define DEBUG 0
# endif
# ifndef PRINTABLE
#  define PRINTABLE 15
# endif
# define PRECISION 0

template <typename T>
struct Element {
  T value;
  int newIndex;
  int oldIndex;

  Element(const T& val, int newIndex, int oldIndex)
    :value(val), newIndex(newIndex), oldIndex(oldIndex) {}
};

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
  std::vector<int> groups;
  void populateGroups(int size);
  std::vector<Element<T> > organizeInGroups(const std::vector<Element<T> >& elements);

  std::vector<int> recursiveMerge(std::vector<Element<T> >& input);
  std::vector<int> lastFew(std::vector<Element<T> >& input);
  void halver(const std::vector<Element<T> >& container, std::vector<Element<T> >& high, std::vector<Element<T> >& low);
  void binaryInsert(std::vector<Element<T> >& sorted, const Element<T>& element, int inserted);
  void extractIndices(std::vector<int>& indices, const std::vector<Element<T> >& sorted);
  
  void clockLog(int range, double sortTime, double transferIn, double transferOut) const;
  double clockCalc(clock_t start, clock_t finish) const;
  void printIntVec(const std::vector<T>& elements) const;
  void printIndexedPairings(const std::vector<Element<T> >& elements) const;
};

#include "PmergeMe.tpp"
