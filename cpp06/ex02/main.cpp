/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:55:32 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/03 19:26:08 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
  int random = std::rand() % 3;
  switch (random)
  {
    case 0:
      return new A;
      break;
    case 1:
      return new B;
      break;
    case 2:
      return new C;
      break;
    default:
      std::cerr << "Error on random function" << std::endl;
      return NULL;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) std::cout << "\033[36mA\033[0m" << std::endl;
  if (dynamic_cast<B*>(p)) std::cout << "\033[33mB\033[0m" << std::endl;
  if (dynamic_cast<C*>(p)) std::cout << "\033[35mC\033[0m" << std::endl;
}

void identify(Base& p) {
  try {
    dynamic_cast<A&>(p);
    std::cout << "\033[96mA\033[0m" << std::endl;
  } catch (std::exception& e) {
    try {
      dynamic_cast<B&>(p);
      std::cout << "\033[93mB\033[0m" << std::endl;
    } catch (std::exception& e) {
      try {
        dynamic_cast<C&>(p);
        std::cout << "\033[95mC\033[0m" << std::endl;
      } catch (std::exception& e) {
        std::cerr << "Error on generated class" << std::endl;
      }
    }
  }
}

int main() {
  std::srand(time(0));
  Base* p;
  for (int i = 0; i < 10; i++) {
    std::cout << "Attempt: " << i + 1 << std::endl;
    p = generate();
    identify(p);
    identify(*p);
    delete p;
    std::cout << std::endl;
  }
}
