/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:41:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/05 22:02:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N < 1) {
		return NULL;
	}

	void* memoryBlock = operator new[](sizeof(Zombie) * N);

	Zombie* horde = static_cast<Zombie*>(memoryBlock);

	for (int i = 0; i < N; i++) {
		new (&horde[i])Zombie(name);
	}
	return horde;
}
