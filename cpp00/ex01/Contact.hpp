/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:33:36 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/28 22:14:49 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact {
public:
	Contact();

	bool setFirstName(const std::string& firstName);
	bool setLastName(const std::string& lastName);
	bool setNickname(const std::string& nickname);
	bool setPhoneNumber(const std::string& phoneNumber);
	bool setDarkestSecret(const std::string& darkestSecret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

private:
	std::string firstName_;
	std::string lastName_;
	std::string nickname_;
	std::string phoneNumber_;
	std::string darkestSecret_;
};
