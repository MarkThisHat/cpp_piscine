/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:05:38 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/29 20:16:07 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>

template<>
clock_t PmergeMe<std::vector, int>::clockStart() {
  return clock();
}

template<>
double PmergeMe<std::vector, int>::clockEnd(clock_t startTime) {
  clock_t endTime = clock();
  double timeTakenUs = double(endTime - startTime)  / CLOCKS_PER_SEC;
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time taken for std::vector : " << timeTakenUs << " µs" << std::endl;
  return timeTakenUs;
}

template<>
clock_t PmergeMe<std::list, int>::clockStart() {
  return clock();
}

template<>
double PmergeMe<std::list, int>::clockEnd(clock_t startTime) {
  clock_t endTime = clock();
  double timeTakenUs = double(endTime - startTime)  / CLOCKS_PER_SEC;
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time taken for std::list : " << timeTakenUs << " µs" << std::endl;
  return timeTakenUs;
}

template <>
void PmergeMe<std::vector, int>::mergeInsertionSort(std::vector<int>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 

  clock_t startTime = clockStart();
  
  container = merge(container, containerSize);
  clockEnd(startTime);
}

template <>
std::vector<int> PmergeMe<std::vector, int>::mergeInsertionSort(const std::vector<int>& container, int containerSize) const {
  std::vector<int> newContainer = container;
  const_cast<PmergeMe*>(this)->mergeInsertionSort(newContainer, containerSize);

  return newContainer;
}
