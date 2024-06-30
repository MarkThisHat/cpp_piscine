/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_print.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:20:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/30 13:47:28 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRETTY_PRINT_HPP
#define PRETTY_PRINT_HPP

#include <iomanip>
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

#define PUT_BLACK(text)    (std::cout << BLACK << text << RESET << std::endl)
#define PUT_RED(text)      (std::cout << RED << text << RESET << std::endl)
#define PUT_GREEN(text)    (std::cout << GREEN << text << RESET << std::endl)
#define PUT_YELLOW(text)   (std::cout << YELLOW << text << RESET << std::endl)
#define PUT_BLUE(text)     (std::cout << BLUE << text << RESET << std::endl)
#define PUT_PINK(text)     (std::cout << PINK << text << RESET << std::endl)
#define PUT_CYAN(text)     (std::cout << CYAN << text << RESET << std::endl)
#define PUT_WHITE(text)    (std::cout << WHITE << text << RESET << std::endl)

#define PUT_L_BLACK(text)  (std::cout << BRIGHT_BLACK << text << RESET << std::endl)
#define PUT_L_RED(text)    (std::cout << BRIGHT_RED << text << RESET << std::endl)
#define PUT_L_GREEN(text)  (std::cout << BRIGHT_GREEN << text << RESET << std::endl)
#define PUT_L_YELLOW(text) (std::cout << BRIGHT_YELLOW << text << RESET << std::endl)
#define PUT_L_BLUE(text)   (std::cout << BRIGHT_BLUE << text << RESET << std::endl)
#define PUT_L_PINK(text)   (std::cout << BRIGHT_PINK << text << RESET << std::endl)
#define PUT_L_CYAN(text)   (std::cout << BRIGHT_CYAN << text << RESET << std::endl)
#define PUT_L_WHITE(text)  (std::cout << BRIGHT_WHITE << text << RESET << std::endl)

#define LAY_BLACK(text)    (std::cout << BLACK << text << RESET)
#define LAY_RED(text)      (std::cout << RED << text << RESET)
#define LAY_GREEN(text)    (std::cout << GREEN << text << RESET)
#define LAY_YELLOW(text)   (std::cout << YELLOW << text << RESET)
#define LAY_BLUE(text)     (std::cout << BLUE << text << RESET)
#define LAY_PINK(text)     (std::cout << PINK << text << RESET)
#define LAY_CYAN(text)     (std::cout << CYAN << text << RESET)
#define LAY_WHITE(text)    (std::cout << WHITE << text << RESET)

#define LAY_L_BLACK(text)  (std::cout << BRIGHT_BLACK << text << RESET)
#define LAY_L_RED(text)    (std::cout << BRIGHT_RED << text << RESET)
#define LAY_L_GREEN(text)  (std::cout << BRIGHT_GREEN << text << RESET)
#define LAY_L_YELLOW(text) (std::cout << BRIGHT_YELLOW << text << RESET)
#define LAY_L_BLUE(text)   (std::cout << BRIGHT_BLUE << text << RESET)
#define LAY_L_PINK(text)   (std::cout << BRIGHT_PINK << text << RESET)
#define LAY_L_CYAN(text)   (std::cout << BRIGHT_CYAN << text << RESET)
#define LAY_L_WHITE(text)  (std::cout << BRIGHT_WHITE << text << RESET)

#define SET_BLACK(text, width)    (std::cout << BLACK << std::setw(width) << std::left << text << RESET)
#define SET_RED(text, width)      (std::cout << RED << std::setw(width) << std::left << text << RESET)
#define SET_GREEN(text, width)    (std::cout << GREEN << std::setw(width) << std::left << text << RESET)
#define SET_YELLOW(text, width)   (std::cout << YELLOW << std::setw(width) << std::left << text << RESET)
#define SET_BLUE(text, width)     (std::cout << BLUE << std::setw(width) << std::left << text << RESET)
#define SET_PINK(text, width)     (std::cout << PINK << std::setw(width) << std::left << text << RESET)
#define SET_CYAN(text, width)     (std::cout << CYAN << std::setw(width) << std::left << text << RESET)
#define SET_WHITE(text, width)    (std::cout << WHITE << std::setw(width) << std::left << text << RESET)

#define SET_L_BLACK(text, width)  (std::cout << BRIGHT_BLACK << std::setw(width) << std::left << text << RESET)
#define SET_L_RED(text, width)    (std::cout << BRIGHT_RED << std::setw(width) << std::left << text << RESET)
#define SET_L_GREEN(text, width)  (std::cout << BRIGHT_GREEN << std::setw(width) << std::left << text << RESET)
#define SET_L_YELLOW(text, width) (std::cout << BRIGHT_YELLOW << std::setw(width) << std::left << text << RESET)
#define SET_L_BLUE(text, width)   (std::cout << BRIGHT_BLUE << std::setw(width) << std::left << text << RESET)
#define SET_L_PINK(text, width)   (std::cout << BRIGHT_PINK << std::setw(width) << std::left << text << RESET)
#define SET_L_CYAN(text, width)   (std::cout << BRIGHT_CYAN << std::setw(width) << std::left << text << RESET)
#define SET_L_WHITE(text, width)  (std::cout << BRIGHT_WHITE << std::setw(width) << std::left << text << RESET)

#endif
