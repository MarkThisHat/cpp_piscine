/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:11:33 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/05 22:06:39 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce();
};

Zombie* zombieHorde(int N, std::string name);
