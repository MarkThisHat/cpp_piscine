/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:06:27 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/28 22:34:15 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void getInput(const std::string& prompt, bool(Contact::*setter)(const std::string&), Contact& contact) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if ((contact.*setter)(input)) {
            break;
        } else {
            std::cerr << "Input cannot be empty. Please try again." << std::endl;
        }
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            Contact contact;

            getInput("Enter first name: ", &Contact::setFirstName, contact);
            getInput("Enter last name: ", &Contact::setLastName, contact);
            getInput("Enter nickname: ", &Contact::setNickname, contact);
            getInput("Enter phone number: ", &Contact::setPhoneNumber, contact);
            getInput("Enter darkest secret: ", &Contact::setDarkestSecret, contact);
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
