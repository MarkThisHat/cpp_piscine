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
void PmergeMe<std::vector, int>::clockLog(int range, double sortTime, double transferIn, double transferOut) const {
  double totalTime = sortTime + transferIn + transferOut;
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time to process a range of " << range 
            << " elements with [std::vector]-> " << totalTime
            << "µs (sort: " << sortTime << "µs + in: " << transferIn
            << "µs + out: " << transferOut << "µs)"<< std::endl;
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
  std::vector<int>::const_iterator iter = container.begin();

  populateGroups(containerSize);

  clock_t inStart = clock();
  std::vector<Element<int> > elements;
  for (int i = 0; i < containerSize; i++) {
    elements.push_back(Element<int>(*iter++, i, 0));
  }
  double inTime = clockCalc(inStart, clock());

  clock_t sortStart = clock();
  std::vector<int> indexes;
  indexes = recursiveMerge(elements);
  double sortTime = clockCalc(sortStart, clock());

  clock_t outStart = clock();
  std::vector<int> sortedContainer;
  for (int i = 0; i < containerSize; i++) {
    sortedContainer.push_back(elements[indexes[i]].value);
  }
  container = sortedContainer;
  double outTime = clockCalc(outStart, clock());
  std::cout << "After: ";
  printContainer(container);
  clockLog(containerSize, sortTime, inTime, outTime);
}

template <>
std::vector<int> PmergeMe<std::vector, int>::mergeInsertionSort(const std::vector<int>& container, int containerSize) const {
  std::vector<int> newContainer = container;
  const_cast<PmergeMe*>(this)->mergeInsertionSort(newContainer, containerSize);

  return newContainer;
}
