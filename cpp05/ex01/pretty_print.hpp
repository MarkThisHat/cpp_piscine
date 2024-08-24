/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_print.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:20:44 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/23 22:56:12 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRETTY_PRINT_HPP
#define PRETTY_PRINT_HPP

#include <iomanip>
#include <iostream>

#define RESET      "\033[0m"
#define BLACK      "\033[30m"
#define RED        "\033[31m"
#define GREEN      "\033[32m"
#define YELLOW     "\033[33m"
#define BLUE       "\033[34m"
#define PINK       "\033[35m"
#define CYAN       "\033[36m"
#define WHITE      "\033[37m"

#define L_BLACK    "\033[90m"
#define L_RED      "\033[91m"
#define L_GREEN    "\033[92m"
#define L_YELLOW   "\033[93m"
#define L_BLUE     "\033[94m"
#define L_PINK     "\033[95m"
#define L_CYAN     "\033[96m"
#define L_WHITE    "\033[97m"

#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_PINK    "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

#define BG_LBLACK  "\033[100m"
#define BG_LRED    "\033[101m"
#define BG_LGREEN  "\033[102m"
#define BG_LYELLOW "\033[103m"
#define BG_LBLUE   "\033[104m"
#define BG_LPINK   "\033[105m"
#define BG_LCYAN   "\033[106m"
#define BG_LWHITE  "\033[107m"

#define BOLD       "\033[1m"
#define UNDERLINE  "\033[4m"
#define BLINK      "\033[5m"
#define REVERSE    "\033[7m"
#define HIDDEN     "\033[8m" 

#define COUT(color, text) std::cout << color << text << RESET
#define PRINT(color, text) COUT(color, text) << std::endl
#define CERR(color, text) std::cerr << color << text << RESET
#define PERR(color, text) CERR(color, text) << std::endl

#endif
