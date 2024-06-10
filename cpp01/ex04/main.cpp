/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:40:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 16:36:32 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int main(int argc, char** argv) {
  if (argc != 4) {
    return Utils::argReject(argv[0]);
  }
  std::cout << "pog" << std::endl;
  return 0;
}
