/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/29 20:15:28 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <deque>

int main() {
  int array[] = {10, 4, 11, 6, 3, 2, 8, 5, 1, 12, 9, 13, 7};

  int size = sizeof(array) / sizeof(array[0]);

  std::vector<int> vec(array, array + size);
  std::list<int> list(array, array + size);
  std::deque<int> deque(array, array + size);

  PmergeMe<std::vector, int> vecMerger;
  const PmergeMe<std::list, int> listMerger;
  PmergeMe<std::deque, int> dequeMerger;
  
  vecMerger.mergeInsertionSort(vec, size);
  vecMerger.printContainer(vec);
  list = listMerger.mergeInsertionSort(list, size);
  listMerger.printContainer(list);
  dequeMerger.mergeInsertionSort(deque, size);
  dequeMerger.printContainer(deque);
}
