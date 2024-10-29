/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/29 15:31:00 by maalexan         ###   ########.fr       */
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

  void mergeInsertionSort(const Container<T, Allocator>& container, int containerSize);

 private:
};

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::PmergeMe() {}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::PmergeMe(const PmergeMe& other) {}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>& PmergeMe<Container, T, Allocator>::operator=(const PmergeMe& other) {
  return *this;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::~PmergeMe() {}

template <typename T>
void print(std::vector<T> vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    if (!(i % 2)) std::cout << "<";
    std::cout << vec[i];
    if (i % 2 || i + 1 == vec.size() ) std::cout << ">";
    std::cout << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void print(std::vector<T> vec, const std::string text) {
  std::cout << text << ": ";
  print(vec);
}

template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void binary_insert(std::vector<T>& sorted, const T& element) {
  typename std::vector<T>::iterator low = sorted.begin();
  typename std::vector<T>::iterator high = sorted.end();
  
  while (low < high) {
    typename std::vector<T>::iterator mid = low + (high - low) / 2;
    if (element < *mid) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  sorted.insert(low, element);
}

template <typename T>
std::vector<T> lastRecursion(std::vector<T>& container, int size) {
  std::vector<T> last;
  last.reserve(size);
  if (size == 1) last.push_back(container[0]);
  if (size == 2) {
    if(container[0] > container[1]) {         
      last.push_back(container[1]);
      last.push_back(container[0]);
    } else {
      last.push_back(container[0]);
      last.push_back(container[1]);
    }
  }
  return last;
}


template <typename T>
void distribute(const std::vector<T>& container, std::vector<T>& high, std::vector<T>& low) {
  typename std::vector<T>::const_iterator iter = container.begin();
  typename std::vector<T>::const_iterator end = container.end();

  while (std::distance(iter, end) > 1) {
    T first = *iter++;
    T second = *iter++;
    if (first > second) {
      low.push_back(second);
      high.push_back(first);
    } else {
      low.push_back(first);
      high.push_back(second);
    }
  }
  if (iter != end) {
    low.push_back(*iter);
  }
}

template <typename T>
std::vector<T> merge(std::vector<T>& container, int size) {
  if (size < 3) return lastRecursion(container, size);
  int newSize = size / 2;

  std::vector<T> sorted;
  std::vector<T> unsorted;
  sorted.reserve(size);
  unsorted.reserve(size - newSize);
  distribute(container, sorted, unsorted);
  print(sorted, "\nhigh");
  print(unsorted, "low");
  sorted = merge(sorted, newSize); 
  for (typename std::vector<T>::iterator iter = unsorted.begin(); iter != unsorted.end(); ++iter) {
      binary_insert(sorted, *iter);
  }
  return sorted;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::mergeInsertionSort(const Container<T, Allocator>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 
  typename Container<T, Allocator>::const_iterator iter = container.begin();
  typename Container<T, Allocator>::const_iterator end = container.end();

  std::vector<T> elements;
  elements.reserve(containerSize);
  while (iter != end) {
    elements.push_back(*iter++);
  }
  print(elements);
  elements = merge(elements, containerSize);
  print(elements);
}
