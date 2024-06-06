/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:59:42 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/05 22:07:53 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 3;
	std::string name = "Zombie";

	Zombie* horde = zombieHorde(N, name);

	for (int i = 0; i < N; ++i) {
		horde[i].announce();
	}

	for (int i = 0; i < N; i++) {
		horde[i].~Zombie();
	}

	operator delete[](horde);

	return 0;
}
