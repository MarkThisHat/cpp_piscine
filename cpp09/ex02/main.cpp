/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/28 19:28:50 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

int main() {
  int array[] = {10, 4, 11, 6, 3, 2, 8, 5, 1, 12, 9, 13, 7};

  int size = sizeof(array) / sizeof(array[0]);
  std::vector<int> vec(array, array + size);
//  PmergeMe<std::vector, int> merger;
  sortWithPairs(vec);
//  merger.mergeInsertionSort(vec, size);

for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
