/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/30 12:07:45 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <sstream>

int* parseArguments(int argc, char* argv[]);

int main(int argc, char* argv[]) {
  int* array;
  int size = argc - 1;
  try {
      array = parseArguments(argc, argv);
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  std::vector<int> vec(array, array + size);
  PmergeMe<std::vector, int> vecMerger;
  std::cout << "Before: ";
  vecMerger.printContainer(vec);
  vecMerger.mergeInsertionSort(vec, size);
  vecMerger.isSorted(vec, "std::vector");

  std::list<int> list(array, array + size);
  const PmergeMe<std::list, int> listMerger;
  list = listMerger.mergeInsertionSort(list, size);
  listMerger.isSorted(list, "std::list");

  delete[] array;
}

int* parseArguments(int argc, char* argv[]) {
  if (argc < 2) throw std::invalid_argument("nothing to sort");

  int* numbers = new int[argc - 1];
  int count = 0;
  for (int i = 1; i < argc; i++) {
    std::istringstream iss(argv[i]);
    int num;

    if (iss >> num && iss.eof() && num >= 0) {
      numbers[count++] = num;
    } else {
      delete[] numbers;
      throw std::invalid_argument("invalid input");
    }
  }
  return numbers;
}

/*
./PmergeMe 10 4 11 6 3 2 8 5 1 12 9 13 7
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

#include <deque>

std::deque<int> deque(array, array + size);
PmergeMe<std::deque, int> dequeMerger;
dequeMerger.mergeInsertionSort(deque, size);
*/
