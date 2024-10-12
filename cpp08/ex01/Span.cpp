/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:07:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/12 12:45:55 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
  throw std::invalid_argument("Provide a N value on construction");
}

Span::Span(unsigned int n): n(n) {}

Span::Span(const Span& other): n(other.n), storedNumbers(other.storedNumbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    n = other.n;
    storedNumbers = other.storedNumbers;
  }
  return *this;
}

unsigned int Span::getMaxSize() const {
  return n;
}
#include <iostream>
void Span::addNumber(int number) {
  std::cout << "current n is " << n << std::endl;
  std::cout << "current stored numbers is " << storedNumbers.size() << std::endl;
  if (n == 0 || n >= storedNumbers.size()) {
    throw std::overflow_error("Span unable to store any more values");
  }
  storedNumbers.insert(number);
}

void Span::validateSpan() const {
  if (storedNumbers.size() < 2) {
    throw std::logic_error("Not enough elements to find a span");
  }
}

int Span::shortestSpan() const {
  validateSpan();

  int shortest = std::numeric_limits<int>::max();  
  std::set<int>::const_iterator iter = storedNumbers.begin();
  std::set<int>::const_iterator next = iter;

  while (++next != storedNumbers.end()) {
    int difference = *next - *iter;
    if (difference < shortest) difference = shortest;
    iter++;
  }
  return shortest;
}

int Span::longestSpan() const {
  validateSpan();

  return *storedNumbers.rbegin() - *storedNumbers.begin();
}
