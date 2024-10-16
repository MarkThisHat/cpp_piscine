/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:07:53 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/16 16:28:10 by maalexan         ###   ########.fr       */
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

void Span::addNumber(int number) {
  if (n == 0 || storedNumbers.size() >= n) {
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

  std::vector<int> differences;
  std::set<int>::const_iterator start = storedNumbers.begin();
  std::set<int>::const_iterator final = storedNumbers.end();
  std::adjacent_difference(start, final, std::back_inserter(differences));
  return *std::min_element(differences.begin() + 1, differences.end());
}

int Span::longestSpan() const {
  validateSpan();

  int minValue = *std::min_element(storedNumbers.begin(), storedNumbers.end());
  int maxValue = *std::max_element(storedNumbers.begin(), storedNumbers.end());

  return maxValue - minValue;
}
