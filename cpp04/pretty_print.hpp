/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_print.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:20:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/26 16:35:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRETTY_PRINT_HPP
#define PRETTY_PRINT_HPP

#include <iostream>

#define RESET         "\033[0m"
#define BLACK         "\033[30m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define YELLOW        "\033[33m"
#define BLUE          "\033[34m"
#define PINK          "\033[35m"
#define CYAN          "\033[36m"
#define WHITE         "\033[37m"

#define BRIGHT_BLACK  "\033[90m"
#define BRIGHT_RED    "\033[91m"
#define BRIGHT_GREEN  "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE   "\033[94m"
#define BRIGHT_PINK   "\033[95m"
#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_WHITE  "\033[97m"

#define PR_BLACK(text)  (std::cout << BLACK << text << RESET << std::endl)
#define PR_RED(text)    (std::cout << RED << text << RESET << std::endl)
#define PR_GREEN(text)  (std::cout << GREEN << text << RESET << std::endl)
#define PR_YELLOW(text) (std::cout << YELLOW << text << RESET << std::endl)
#define PR_BLUE(text)   (std::cout << BLUE << text << RESET << std::endl)
#define PR_PINK(text)   (std::cout << PINK << text << RESET << std::endl)
#define PR_CYAN(text)   (std::cout << CYAN << text << RESET << std::endl)
#define PR_WHITE(text)  (std::cout << WHITE << text << RESET << std::endl)

#define PL_BLACK(text)  (std::cout << BRIGHT_BLACK << text << RESET << std::endl)
#define PL_RED(text)    (std::cout << BRIGHT_RED << text << RESET << std::endl)
#define PL_GREEN(text)  (std::cout << BRIGHT_GREEN << text << RESET << std::endl)
#define PL_YELLOW(text) (std::cout << BRIGHT_YELLOW << text << RESET << std::endl)
#define PL_BLUE(text)   (std::cout << BRIGHT_BLUE << text << RESET << std::endl)
#define PL_PINK(text)   (std::cout << BRIGHT_PINK << text << RESET << std::endl)
#define PL_CYAN(text)   (std::cout << BRIGHT_CYAN << text << RESET << std::endl)
#define PL_WHITE(text)  (std::cout << BRIGHT_WHITE << text << RESET << std::endl)

#endif
