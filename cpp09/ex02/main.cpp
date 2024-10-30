/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:14:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/30 11:42:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
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
  std::cout << "After: ";
  vecMerger.printContainer(vec);


  std::list<int> list(array, array + size);
  const PmergeMe<std::list, int> listMerger;
  std::cout << "Before: ";
  listMerger.printContainer(list);
  list = listMerger.mergeInsertionSort(list, size);
  std::cout << "After: ";
  listMerger.printContainer(list);


  std::deque<int> deque(array, array + size);
  PmergeMe<std::deque, int> dequeMerger;
  std::cout << "\nBefore: ";
  dequeMerger.printContainer(deque);
  dequeMerger.mergeInsertionSort(deque, size);
  std::cout << "After: ";
  dequeMerger.printContainer(deque);

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
*/
