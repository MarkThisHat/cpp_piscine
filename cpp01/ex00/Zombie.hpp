/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:11:33 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/31 14:12:02 by maalexan         ###   ########.fr       */
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

Zombie* newZombie(std::string name);
void randomChump(std::string name);
