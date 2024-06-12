/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:59:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/12 14:11:51 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
  int N = 3;
  std::string name = "Zombie Horde Member";

  Zombie* horde = zombieHorde(N, name);

  for (int i = 0; i < N; ++i) {
    horde[i].announce();
  }

  delete[] horde;

  horde = zombieHorde(5, "Another zombie");
  for (int i = 0; i < N; ++i) {
    horde[i].announce();
  }
  delete[] horde;

  return 0;
}
