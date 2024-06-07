/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:06:27 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/02 18:37:37 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void getInput(const std::string& prompt, bool(Contact::*setter)(const std::string&), Contact& contact) {
	std::string input;

	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if ((contact.*setter)(input) || std::cin.eof()) {
			break;
		} else {
			std::cerr << "Invalid input." << std::endl;
		}
	}
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (std::cin.eof()) {
			std::cout << std::endl;
			break;
		}

		if (command == "ADD") {
			Contact contact;

			getInput("First name: ", &Contact::setFirstName, contact);
			getInput("Last name: ", &Contact::setLastName, contact);
			getInput("Nickname: ", &Contact::setNickname, contact);
			getInput("Phone number: ", &Contact::setPhoneNumber, contact);
			getInput("Darkest secret: ", &Contact::setDarkestSecret, contact);
			phoneBook.addContact(contact);
		} else if (command == "SEARCH") {
			phoneBook.searchContacts();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cerr << "Invalid command." << std::endl;
		}
	}
	return 0;
}
