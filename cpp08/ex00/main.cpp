/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:52 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/11 20:34:54 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <deque>
#include <vector>
#include "easyfind.hpp"

int main() {
  int array[] = {10, 11, 12, 13, 15};
  int size = sizeof(array) / sizeof(array[0]);
  std::vector<int> vec(array, array + size);
  
  std::vector<int>::iterator vecIter = easyfind(vec, 13);
  std::cout << "Found vector value " << *vecIter << std::endl;

  try {
    vecIter = easyfind(vec, 14);
    std::cout << "Found vector value " << *vecIter << std::endl;
  } catch (const std::runtime_error& error) {
    std::cerr << error.what() << std::endl;
  }

  std::deque<int> deque;
  deque.push_back(10);
  deque.push_back(20);
  deque.push_back(30);
  deque.push_back(40);

  std::deque<int>::iterator dequeIter = easyfind(deque, 30);
  std::cout << "Found deque value " << *dequeIter << std::endl;

  try {
    dequeIter = easyfind(deque, 14);
    std::cout << "Found deque value " << *dequeIter << std::endl;
  } catch (const std::runtime_error& error) {
    std::cerr << error.what() << std::endl;
  }
}
