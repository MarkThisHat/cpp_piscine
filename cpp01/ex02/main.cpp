/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:00:17 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/08 23:13:42 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
	std::string		brain = "HI THIS IS BRAIN.";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "Memory address of string: " << &brain << std::endl;
	std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string: " << brain << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF: " << stringREF << std::endl;

	return 0;
}
