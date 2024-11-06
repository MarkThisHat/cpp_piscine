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

/* part go away
template <typename U, typename T>
void printElement(const std::pair<U, std::pair<T, int> >& element) {
    std::cout << "[ U: ";
    printSimplePair(element.first);
    std::cout << ", T, int: ";
    printElement(element.second); 
    std::cout << " ]";
}
*/

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

  template<typename U>
  std::vector<std::pair< U, std::pair<T, int> > > wrapper(const std::vector<std::pair<U, std::pair<T, int> > >& input);

  template<typename U>
  std::vector<int> recursiveMerge(std::vector<std::pair<U, std::pair<T, int> > >& input);
  
  template<typename U>
  void halver(const std::vector<std::pair<U, std::pair<T, int> > >& container, std::vector<std::pair<U, std::pair<T, int> > >& high, std::vector<std::pair<U, std::pair<T, int> > >& low);

  std::vector<int> lastPair(bool firstHigher);
};

#include "PmergeMe.tpp"

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::newMergeInsertionSort(Container<T, Allocator>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 
  typename Container<T, Allocator>::const_iterator iter = container.begin();

  std::vector<std::pair< std::pair<int, int> , std::pair<T, int> > > elements;
  elements.reserve(containerSize);
  for (int i = 0; i < containerSize; i++) {
    elements.push_back(std::make_pair(std::make_pair(0, 0), std::make_pair(*iter++, i)));
  }

std::vector<std::pair< std::pair<int, int> , std::pair<T, int> > > sorted;
std::vector<std::pair< std::pair<int, int> , std::pair<T, int> > > unsorted;
sorted.reserve(containerSize / 2);
unsorted.reserve(containerSize - containerSize / 2);
halver(elements, sorted, unsorted);

  printElements(elements);

  std::cout << "sorted (high): " << std::endl;
  printElements(sorted);
  std::cout << "unsorted (low): " << std::endl;
  printElements(unsorted);

    recursiveMerge(sorted);

}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<int> PmergeMe<Container, T, Allocator>::lastPair(bool firstHigher) {
    std::vector<int> result;
    if (firstHigher) {
        result.push_back(0);
        result.push_back(1);
    } else {
        result.push_back(1);
        result.push_back(0);
    }
    return result;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
template <typename U>
std::vector<int> PmergeMe<Container, T, Allocator>::recursiveMerge(std::vector<std::pair<U, std::pair<T, int> > >& input) {
    int size = input.size();
    if (size < 3) return lastPair(input[0].second.first > input[1].second.first);
    std::vector<int> indexes;

    std::vector<std::pair<U , std::pair<T, int> > > sorted;
    std::vector<std::pair<U , std::pair<T, int> > > unsorted;
    sorted.reserve(size / 2);
    unsorted.reserve(size - size / 2);
    halver(input, sorted, unsorted);

std::cout << "\nFirst halving:" << std::endl;
    printElements(input);

  std::cout << "sorted (high): " << std::endl;
  printElements(sorted);
  std::cout << "unsorted (low): " << std::endl;
  printElements(unsorted);

  return indexes;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
template <typename U>
void PmergeMe<Container, T, Allocator>::halver(const std::vector<std::pair<U, std::pair<T, int> > >& container, 
            std::vector<std::pair<U, std::pair<T, int> > >& high, 
            std::vector<std::pair<U, std::pair<T, int> > >& low) {
    typename std::vector<std::pair<U, std::pair<T, int> > >::const_iterator iter = container.begin();
    typename std::vector<std::pair<U, std::pair<T, int> > >::const_iterator end = container.end();

    int i = 0;
    
    while (std::distance(iter, end) > 1) {
        const U& firstOuter = iter->first;
        T firstValue = iter->second.first;            
        T secondValue = (iter + 1)->second.first;     
        const U& secondOuter = (iter + 1)->first;

        
        if (firstValue > secondValue) {
            low.push_back(std::make_pair(secondOuter, std::make_pair(secondValue, i)));
            high.push_back(std::make_pair(firstOuter, std::make_pair(firstValue, i)));
        } else {
            low.push_back(std::make_pair(firstOuter, std::make_pair(firstValue, i)));
            high.push_back(std::make_pair(secondOuter, std::make_pair(secondValue, i)));
        }

        iter += 2;  
        i++;
    }

    if (iter != end) {
        low.push_back(std::make_pair(iter->first, std::make_pair(iter->second.first, i)));  
    }
}


/*
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
*/