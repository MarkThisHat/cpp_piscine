/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:42:39 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/02 18:41:40 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName_(""),
					 lastName_(""),
					 nickname_(""),
					 phoneNumber_(""),
					 darkestSecret_("") {}

bool Contact::isInputInvalid(const std::string& input) const {
    if (input.empty()) {
        return true;
    }
    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isspace(static_cast<unsigned char>(input[i]))) {
            return false;
        }
    }
    return true;
}

bool Contact::setFirstName(const std::string& firstName) {
	if (isInputInvalid(firstName)) {
		return false;
	}
	firstName_ = firstName;
	return true;
}

bool Contact::setLastName(const std::string& lastName) {
	if (isInputInvalid(lastName)) {
		return false;
	}
	lastName_ = lastName;
	return true;
}

bool Contact::setNickname(const std::string& nickname) {
	if (isInputInvalid(nickname)) {
		return false;
	}
	nickname_ = nickname;
	return true;
}

bool Contact::setPhoneNumber(const std::string& phoneNumber) {
	if (isInputInvalid(phoneNumber)) {
		return false;
	}
	for (t_iter it = phoneNumber.begin(); it != phoneNumber.end(); ++it) {
		if (!std::isdigit(static_cast<unsigned char>(*it)) &&
			*it != '(' && *it != ')' && *it != '-') {
				return false;
			}
	}

	phoneNumber_ = phoneNumber;
	return true;
}

bool Contact::setDarkestSecret(const std::string& darkestSecret) {
	if (isInputInvalid(darkestSecret)) {
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
