/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:05:03 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/12 12:43:08 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main() {
  Span smallSpan(7);
  /*int array[] = {6129, 25, 17, 400, 73918, 1000003, 3};

  smallSpan.addNumbers(array, array + 7);*/

  smallSpan.addNumber(6129);
  smallSpan.addNumber(25);
  smallSpan.addNumber(17);
  smallSpan.addNumber(400);
  smallSpan.addNumber(73918);
  smallSpan.addNumber(1000003);
  smallSpan.addNumber(3);

  std::cout << "Shortest Span: " << smallSpan.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << smallSpan.longestSpan() <<  std::endl;
}
