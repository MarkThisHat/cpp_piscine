/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:05:38 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/30 19:53:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>

template<>
void PmergeMe<std::vector, int>::clockLog(int range, double sortTime) const {
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time to process a range of " << range 
            << " elements with [std::vector]-> "
            << sortTime << "µs" << std::endl;
}

template<>
void PmergeMe<std::list, int>::clockLog(int range, double sortTime, double transferIn, double transferOut) const {
  double totalTime = sortTime + transferIn + transferOut;
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time to process a range of " << range 
            << " elements with [ std::list ]-> " << totalTime
            << "µs (sort: " << sortTime << "µs + in: " << transferIn
            << "µs + out: " << transferOut << "µs)"<< std::endl;
}

template <>
void PmergeMe<std::vector, int>::mergeInsertionSort(std::vector<int>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 
  clock_t sortStart = clock();
  container.reserve(containerSize);
  container = merge(container, containerSize);

  double sortTime = clockCalc(sortStart, clock());
  std::cout << "After: ";
  printContainer(container);
  clockLog(containerSize, sortTime);
}

template <>
std::vector<int> PmergeMe<std::vector, int>::mergeInsertionSort(const std::vector<int>& container, int containerSize) const {
  std::vector<int> newContainer = container;
  const_cast<PmergeMe*>(this)->mergeInsertionSort(newContainer, containerSize);

  return newContainer;
}
