/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/30 19:56:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

# ifndef DEBUG
#  define DEBUG 0
# endif
# ifndef PRINTABLE
#  define PRINTABLE 15
# endif
# define PRECISION 0

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

  void newMergeInsertionSort(Container<T, Allocator>& container, int containerSize);
 private:
  std::vector<T> merge(std::vector<T>& container, int size);
  void distribute(const std::vector<T>& container, std::vector<T>& high, std::vector<T>& low);
  std::vector<T> lastRecursion(std::vector<T>& container, int size);
  void binaryInsert(std::vector<T>& sorted, const T& element);
  void clockLog(int range, double sortTime) const;
  void clockLog(int range, double sortTime, double transferIn, double transferOut) const;
  double clockCalc(clock_t start, clock_t finish) const;

  template<typename U>
  std::vector<std::pair< U, std::pair<T, int> > > wrapper(const std::vector<std::pair<U, std::pair<T, int> > >& input);
};

#include "PmergeMe.tpp"

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::newMergeInsertionSort(Container<T, Allocator>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 
  typename Container<T, Allocator>::const_iterator iter = container.begin();

  std::vector<std::pair<T, int> > elements;
  elements.reserve(containerSize);
  for (int i = 0; i < containerSize; i++) {
    elements.push_back(std::make_pair(*iter++, i));
  }

}

template <template <typename, typename> class Container, typename T, typename Allocator>
template <typename U>
std::vector<std::pair< U, std::pair<T, int> > > PmergeMe<Container, T, Allocator>::wrapper(const std::vector<std::pair<U, std::pair<T, int> > >& input) {
    std::vector<std::pair<U, std::pair<T, int> > > result;

    for (size_t i = 0; i < input.size(); i++) {
        result.push_back(std::make_pair(input[i].first, 
          std::make_pair(input[i].second.first, static_cast<int>(i))));
    }
    return result;
}

template <typename T>
void printElements(const std::vector<T>& elements) {
    for (typename std::vector<T>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        printElement(*it);
        std::cout << " ";
    }
    std::cout << std::endl;
}

// Print function for a single pair (T, int)
template <typename T>
void printElement(const std::pair<T, int>& element) {
    std::cout << "(" << element.first << ", " << element.second << ")";
}

// Print function for a nested pair ((U, (T, int)))
template <typename U, typename T>
void printElement(const std::pair<U, std::pair<T, int> >& element) {
    std::cout << "(" << element.first << ", (" << element.second.first << ", " << element.second.second << "))";
}
