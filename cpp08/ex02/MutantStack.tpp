/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 10:07:49 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/15 11:08:24 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other):
 std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
  if (this != &other) {
    std::stack<T>::operator=(other);
  }
  return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

/*
  This implementation is technically a "hack" because it
  "forces" the compiler to treat the inherited stack's
  conteiner as a std::deque (which is underneath most, if
  not all, commonly used implementations of std::stack.
  It works just as fine with the following:
  return this->c;
*/
template <typename T>
std::deque<T>& MutantStack<T>::getUnderlyingContainer() {
  return *reinterpret_cast<std::deque<T>*>(&this->c);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return getUnderlyingContainer().begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return getUnderlyingContainer().end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
  return getUnderlyingContainer().begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
  return getUnderlyingContainer().end();
}
