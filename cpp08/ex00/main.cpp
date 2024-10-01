/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:36:52 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/01 16:32:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
  int array[] = {10, 11, 12, 13, 15};
  int size = sizeof(array) / sizeof(array[0]);
  std::vector<int> vec(array, array + size);

  std::vector<int>::iterator it = easyfind(vec, 13);
  std::cout << "Found value " << *it << std::endl;

  try {
    it = easyfind(vec, 14);
    std::cout << "Found value " << *it << std::endl;
  } catch (const std::runtime_error& error) {
    std::cerr << error.what() << std::endl;
  }

}