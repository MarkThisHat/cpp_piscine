/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:38:03 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/28 22:07:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

class PhoneBook {
public:
	PhoneBook();

	void addContact(const Contact& contact);
	void searchContacts() const;

private:
	static const int MAX_CONTACTS = 8;
	Contact contacts_[MAX_CONTACTS];
	int contactCount_;
	int nextIndex_;

	void displayContactList() const;
	void displayContactDetails(int index) const;
	std::string truncate(const std::string& str, std::size_t width) const;
};
