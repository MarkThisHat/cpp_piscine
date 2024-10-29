/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:05:38 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/29 20:27:45 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>

template<>
double PmergeMe<std::vector, int>::clockEnd(clock_t startTime, int range) {
  clock_t endTime = clock();
  double timeTakenUs = double(endTime - startTime)  / CLOCKS_PER_SEC;
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time to process a range of " << range 
            << " elements with std::vector : "
            << timeTakenUs << " µs" << std::endl;
  return timeTakenUs;
}

template<>
double PmergeMe<std::list, int>::clockEnd(clock_t startTime, int range) {
  clock_t endTime = clock();
  double timeTakenUs = double(endTime - startTime)  / CLOCKS_PER_SEC;
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time to process a range of " << range 
            << " elements with std::list : "
            << timeTakenUs << " µs" << std::endl;
  return timeTakenUs;
}

template <>
void PmergeMe<std::vector, int>::mergeInsertionSort(std::vector<int>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 

  clock_t startTime = clock();
  
  container = merge(container, containerSize);
  clockEnd(startTime, containerSize);
}

template <>
std::vector<int> PmergeMe<std::vector, int>::mergeInsertionSort(const std::vector<int>& container, int containerSize) const {
  std::vector<int> newContainer = container;
  const_cast<PmergeMe*>(this)->mergeInsertionSort(newContainer, containerSize);

  return newContainer;
}
