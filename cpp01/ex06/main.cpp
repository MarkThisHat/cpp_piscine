/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:07:10 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/12 10:46:34 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[]) {
  Harl harl;

  if (argc == 2) {
    harl.complain(argv[1]);
  } else {
    harl.complain("Whatever, dude");
  }
}
