/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:05:03 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/16 16:18:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Span.hpp"

int setlargeSpan(int argc, char *argv) {
  int number;
  std::stringstream stringStream(argv);

  if (argc != 2 || !(stringStream >> number) || !stringStream.eof()) {
    std::cerr << "Provide a positive integer as second argument" << std::endl;
    return -1;
  }
  if (number < 1 || number > 100000) {
    std::cerr << "Provide an integer between 1 and 100.000" << std::endl;
    return -1;
  }
  return number;
}

void providedMain() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

int main(int argc, char **argv) {
  providedMain();

  Span smallSpan(7);
  int array[] = {6129, 25, 17, 400, 73918, 1000003, 3};

  smallSpan.addNumbers(array, array + 7);

  std::cout << "\nShortest Span: " << smallSpan.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << smallSpan.longestSpan() <<  std::endl;

  if (argc < 2) return 0;

  int interval = setlargeSpan(argc, argv[1]);
  if (interval < 1) return 1;

  const unsigned int largeSize = 15000;
  Span largeSpan(largeSize);

  try {
    for (unsigned int i = 0; i < largeSize; i++) {
      largeSpan.addNumber(i * interval);
    }
    std::cout << "\nSuccessfully added " << largeSize << " numbers." << std::endl;
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;

    largeSpan.addNumber(14);
  } catch (const std::exception& e) {
      std::cerr << "\nException: " << e.what() << std::endl;
  }
}
