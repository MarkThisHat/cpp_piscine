/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:00:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/14 16:26:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
 public:
  MutantStack();
  MutantStack(const MutantStack& other);
  MutantStack& operator=(const MutantStack& other);
  ~MutantStack();

  std::deque<T>& getUnderlyingContainer() {
    return *reinterpret_cast<std::deque<T>*>(&this->c); //
  };

  typename std::deque<T>::iterator begin();
  typename std::deque<T>::iterator end();
  typename std::deque<T>::const_iterator begin() const;
  typename std::deque<T>::const_iterator end() const;
};

#include "MutantStack.tpp"