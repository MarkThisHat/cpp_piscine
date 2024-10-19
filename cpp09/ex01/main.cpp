/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:11:01 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/19 17:45:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

bool validOperand(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

bool validInput(const std::string& str, size_t i) {
  size_t length = str.length();

  return (std::isdigit(str[i]) || validOperand(str[i])) &&
   (i == length - 1 || str[i + 1] == ' ') && (i == 0 || str[i - 1] == ' ');
}

int main(int argc, char **argv) {
    if (argc < 2) return -1;
    std::string input = argv[1];

    for (size_t i = 0; i < input.length(); ++i) {
        if (validInput(input, i)) {
          std::cout << "Found valid digit: " << input[i] << std::endl;
        } else if (!std::isspace(input[i])) {
          std::cerr << "Bad input" << input[i] << "i is: " << i << std::endl;
          break;
        }
    }
    return 0;
}
