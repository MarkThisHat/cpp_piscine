/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:00:37 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/12 16:37:21 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

  std::deque<T>::iterator iterator begin();
  std::deque<T>::iterator iterator end();
  const std::deque<T>::iterator iterator begin() const;
  const std::deque<T>::iterator iterator end() const;
};

#include "MutantStack.tpp"