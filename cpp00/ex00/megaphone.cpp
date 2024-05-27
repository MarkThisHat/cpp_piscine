/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:58:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/05/26 22:25:05 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Megaphone {
    public:
        static std::string amplify(const std::string& input) {
            std::string output;
            for (std::string::const_iterator it = input.begin(); it != input.end(); it++) {
                output += std::toupper(*it);
            }
            return output;
        }
};

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    std::string message;
    for (int i = 1;i < argc; i++) {
        message += Megaphone::amplify(argv[i]);
        if (i < argc -1) message += ' ';
    }
    std::cout << message << std::endl;
}
