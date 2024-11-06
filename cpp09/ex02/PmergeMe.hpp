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

inline void printSimplePair(const std::pair<int, int>& p) {
    std::cout << "<first: " << p.first << ", second: " << p.second << ">";
}

template <typename T>
void printElement(const std::pair<T, int>& element) {
    std::cout << "<value: " << element.first << ", index: " << element.second << ">";
}

template <typename U, typename T>
void printElement(const std::pair<U, std::pair<T, int> >& element) {
    std::cout << "[ ";
    printElement(element.second); 
    std::cout << " ]";
}

template <typename T>
void printElement(const std::pair<std::pair<std::pair<int, int>, std::pair<int, int> >, std::pair<T, int> >& element) {
    std::cout << "[ Outer U: { ";
    printSimplePair(element.first.first);
    std::cout << ", ";
    printSimplePair(element.first.second);
    std::cout << " }, Inner T, int: ";
    printElement(element.second);
    std::cout << " ]";
}

template <typename T>
void printElements(const std::vector<T>& elements) {
    for (typename std::vector<T>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        printElement(*it);
        std::cout << " ";
    }
    std::cout << std::endl;
}

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

  std::vector<int> recursiveMerge(std::vector<std::pair<T, int> >& input);
  
  void halver(const std::vector<std::pair<T, int> >& container, std::vector<std::pair<T, int> >& high, std::vector<std::pair<T, int> >& low);

  std::vector<int> lastPair(std::vector<std::pair<T, int> >& input);
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

  std::vector<std::pair<T, int> > sorted;
  std::vector<std::pair<T, int> > unsorted;
  sorted.reserve(containerSize / 2);
  unsorted.reserve(containerSize - containerSize / 2);
  halver(elements, sorted, unsorted);
  std::vector<int> indexes;
  indexes = recursiveMerge(sorted);
}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<int> PmergeMe<Container, T, Allocator>::lastPair(std::vector<std::pair<T, int> >& input) {
  int size = input.size();
  std::vector<int> result;
  result.reserve(size);
  result.push_back(0);
  if (size == 1) return result;
  if (input[0].first < input[1].first) {
    result.push_back(1);
  } else {
    result.insert(result.begin(), 1);
  }
  return result;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<int> PmergeMe<Container, T, Allocator>::recursiveMerge(std::vector<std::pair<T, int> >& input) {
  int size = input.size();
  if (size < 3) return lastPair(input);
  std::vector<int> indexes;

  std::vector<std::pair<T, int> > sorted;
  std::vector<std::pair<T, int> > unsorted;
  sorted.reserve(size / 2);
  unsorted.reserve(size - size / 2);
  halver(input, sorted, unsorted);
  indexes = recursiveMerge(sorted);

  std::vector<std::pair<T, int> > reSorted;
  std::vector<std::pair<T, int> > reUnsorted;
  reSorted.reserve(sorted.size());
  reUnsorted.reserve(unsorted.size());
  for (size_t i = 0; i < indexes.size(); i++) {
    reSorted.push_back(sorted[indexes[i]]);
    reUnsorted.push_back(unsorted[indexes[i]]);
  }
  sorted = reSorted;
  unsorted = reUnsorted;
  //jacobastal binary insert
  return indexes;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::halver(const std::vector<std::pair<T, int> >& container, std::vector<std::pair<T, int> >& high, std::vector<std::pair<T, int> >& low) {
  typename std::vector<std::pair<T, int> >::const_iterator iter = container.begin();
  typename std::vector<std::pair<T, int> >::const_iterator end = container.end();
  int i = 0;
  
  while (std::distance(iter, end) > 1) {
    T firstValue = iter->first;
    T secondValue = (iter + 1)->first;

    if (firstValue > secondValue) {
      low.push_back(std::make_pair(secondValue, i));
      high.push_back(std::make_pair(firstValue, i));
    } else {
      low.push_back(std::make_pair(firstValue, i));
      high.push_back(std::make_pair(secondValue, i));
    }
    iter += 2;
    i++;
  }

  if (iter != end) {
    low.push_back(std::make_pair(iter->first, i));
  }
}
