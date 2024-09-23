/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:34:35 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/23 13:30:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "Array.hpp"

int main() {
  Array<int> defaultArray;
  std::cout << DEFAULT_TEST << defaultArray.size() << std::endl;

  Array<int> sizedArray(5);
  std::cout << SIZED_TEST << sizedArray.size() << std::endl;

  sizedArray[0] = 10;
  sizedArray[1] = 20;
  std::cout << FIRST_SIZED_ELEM << sizedArray[0] << std::endl;
  std::cout <<  SECOND_SIZED_ELEM << sizedArray[1] << std::endl;

  try {
      std::cout << OUT_OF_BOUNDS << sizedArray[10] << std::endl;
  } catch (const std::out_of_range& e) {
      std::cout << EXCEPTION_CAUGH << e.what() << std::endl;
  }

  Array<int> copyArray = sizedArray;
  std::cout << COPIED_TEST << copyArray.size() << std::endl;
  std::cout << COPIED_FIRST_ELEM << copyArray[0] << std::endl;

  sizedArray[0] = 100;
  std::cout << MODIFIED_SIZED_ARRAY << sizedArray[0] << std::endl;
  std::cout << COPIED_ARRAY_FIRST_ELEM << copyArray[0] << std::endl;

  Array<int> assignedArray;
  assignedArray = sizedArray;
  std::cout << ASSIGNED_ARRAY_SIZE << assignedArray.size() << std::endl;
  std::cout << ASSIGNED_ARRAY_FIRST_ELEM << assignedArray[0] << std::endl;

  const Array<int> constArray = sizedArray;
  std::cout << CONST_ARRAY_FIRST_ELEM << constArray[0] << std::endl;
  return 0;
}
