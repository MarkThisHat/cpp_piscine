/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:41:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/12 14:07:08 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N < 1) {
		return NULL;
	}

	Zombie* horde = new Zombie[N];
    
	for (int i = 0; i < N; i++) {
		new (&horde[i]) Zombie(name);
	}
	return horde;
}

/* Alternative using operator new:
	void* memoryBlock = operator new[](sizeof(Zombie) * N);

	Zombie* horde = static_cast<Zombie*>(memoryBlock);

	main.cpp will have to use:
		operator delete[](horde);
*/