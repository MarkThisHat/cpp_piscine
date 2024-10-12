/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:05:03 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/12 13:16:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Span.hpp"

int setlargeSpan(char *argv) {
  int number;
  std::stringstream stringStream(argv);

  if (!(stringStream >> number) || !stringStream.eof()) {
    std::cerr << "Provide a positive integer as second argument" << std::endl;
    return -1;
  }
  if (number < 1 || number > 100000) {
    std::cerr << "Provide an integer between 1 and 100.000" << std::endl;
    return -1;
  }
  return number;
}

int main(int argc, char **argv) {
  Span smallSpan(7);
  int array[] = {6129, 25, 17, 400, 73918, 1000003, 3};

  smallSpan.addNumbers(array, array + 7);

  std::cout << "Shortest Span: " << smallSpan.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << smallSpan.longestSpan() <<  std::endl;

  if (argc < 2) return 0;
  int interval = setlargeSpan(argv[1]);
  if (argc > 2 || interval < 1) return 1;

  const unsigned int largeSize = 15000;
  Span largeSpan(largeSize);

  try {
    for (unsigned int i = 0; i < largeSize; ++i) {
      largeSpan.addNumber(i * interval);
    }
    std::cout << "\nSuccessfully added " << largeSize << " numbers." << std::endl;
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;

  } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
  }
}
