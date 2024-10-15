/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:46:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/15 11:33:55 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main() {
  MutantStack<int> mstack;
  std::list<int> list;

  mstack.push(5);
  list.push_back(5);
  mstack.push(17);
  list.push_back(17);
  std::cout << mstack.top() << std::endl;
  std::cout << list.back() << std::endl;
  mstack.pop();
  list.pop_back();
  std::cout << mstack.size() << std::endl;
  std::cout << list.size() << std::endl;
  mstack.push(3);
  list.push_back(3);
  mstack.push(5);
  list.push_back(5);
  mstack.push(737);
  list.push_back(737);
  mstack.push(0);
  list.push_back(0);
  MutantStack<int>::iterator it = mstack.begin();
  std::list<int>::iterator it_list = list.begin();
  MutantStack<int>::iterator end = mstack.end();
  std::list<int>::iterator list_end = list.end();
  
  ++it;
  --it;
  while (it != end && it_list != list_end) {
    std::cout << "Mutant Stack: ";
    std::cout << *it << std::endl;
    ++it;
    std::cout << "Default list: ";
    std::cout << *it_list++ << std::endl;
  }
  std::stack<int> s(mstack);

  MutantStack<int> newMstack;
  while (!s.empty()) {
    newMstack.push(s.top());
    s.pop();
  }

  MutantStack<int>::const_iterator cit = newMstack.begin();
  MutantStack<int>::const_iterator cite = newMstack.end();
  
  std::cout << "Iterating over new MutantStack with const iter:" << std::endl;
  while (cit != cite) {
    std::cout << *--cite << std::endl;
  }

  return 0;
}
