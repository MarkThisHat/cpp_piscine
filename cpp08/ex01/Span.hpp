/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:58:01 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/12 12:38:29 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <set>
#include <stdexcept>

class Span {
 public:
  Span(unsigned int n);
  ~Span();
  Span(const Span& other);
  Span& operator=(const Span& other);

  unsigned int getMaxSize() const;

  void addNumber(int number);
  int shortestSpan() const;
  int longestSpan() const;

  template <typename Iterator>
  void addNumbers(Iterator first, Iterator last);
 
 private:
  unsigned int n;
  std::set<int> storedNumbers;

  void validateSpan() const;
  Span();
  
};

#include "Span.tpp"