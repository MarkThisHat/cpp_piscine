/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:42:25 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/02 20:51:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie* foo = newZombie("Foo");
	Zombie* bar = newZombie("Bar");

	foo->announce();
	bar->announce();

	randomChump("Baz");

	delete foo;
	delete bar;

	return 0;
}
