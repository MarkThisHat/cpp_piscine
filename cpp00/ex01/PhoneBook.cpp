/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:56:39 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/28 22:42:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount_(0), nextIndex_(0) {}

void PhoneBook::addContact(const Contact& contact) {
	contacts_[nextIndex_] = contact;
	nextIndex_ = (nextIndex_ + 1) % MAX_CONTACTS;
	if (contactCount_ < MAX_CONTACTS) {
		contactCount_++;
	}
}

void PhoneBook::searchContacts() const {
	if (contactCount_ == 0) {
		std::cerr << "Phonebook is empty." << std::endl;
		return;
	}

	displayContactList();
	std::cout << "Enter the index of the contact to display: ";
	int index;
	std::cin >> index;
	if (std::cin.fail() || index < 0 || index >= contactCount_) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Invalid index." << std::endl;
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	displayContactDetails(index);
}

void PhoneBook::displayContactList() const {
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount_; i++) {
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncate(contacts_[i].getFirstName(), 10) << "|"
				  << std::setw(10) << truncate(contacts_[i].getLastName(), 10) << "|"
				  << std::setw(10) << truncate(contacts_[i].getNickname(), 10) << std::endl;
	}
}

void PhoneBook::displayContactDetails(int index) const {
	const Contact& contact = contacts_[index];
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncate(const std::string& str, std::size_t width) const {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	}
	return str;
}
