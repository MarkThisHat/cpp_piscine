/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/28 14:59:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

int main() {
  int array[] = {10, 4, 11, 6, 3, 2, 8, 5, 1, 12, 9, 13, 7};

  int size = sizeof(array) / sizeof(array[0]);
  std::vector<int> vec(array, array + size);
  PmergeMe<std::vector, int> merger;

  merger.mergeInsertionSort(vec, size);
}
