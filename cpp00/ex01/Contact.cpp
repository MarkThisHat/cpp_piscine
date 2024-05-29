/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:42:39 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/28 22:16:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName_(""),
					 lastName_(""),
					 nickname_(""),
					 phoneNumber_(""),
					 darkestSecret_("") {}

bool Contact::setFirstName(const std::string& firstName) {
	if (firstName.empty()) {
		return false;
	}
	firstName_ = firstName;
	return true;
}

bool Contact::setLastName(const std::string& lastName) {
	if (lastName.empty()) {
		return false;
	}
	lastName_ = lastName;
	return true;
}

bool Contact::setNickname(const std::string& nickname) {
	if (nickname.empty()) {
		return false;
	}
	nickname_ = nickname;
	return true;
}

bool Contact::setPhoneNumber(const std::string& phoneNumber) {
	if (phoneNumber.empty()) {
		return false;
	}
	phoneNumber_ = phoneNumber;
	return true;
}

bool Contact::setDarkestSecret(const std::string& darkestSecret) {
	if (darkestSecret.empty()) {
		return false;
	}
	darkestSecret_ = darkestSecret;
	return true;
}

std::string Contact::getFirstName() const {
	return firstName_;
}

std::string Contact::getLastName() const {
	return lastName_;
}

std::string Contact::getNickname() const {
	return nickname_;
}

std::string Contact::getPhoneNumber() const {
	return phoneNumber_;
}

std::string Contact::getDarkestSecret() const {
	return darkestSecret_;
}
