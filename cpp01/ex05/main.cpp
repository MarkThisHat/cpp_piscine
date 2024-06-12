/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:07:10 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/12 09:08:05 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
  Harl harl;

  harl.complain("DEBUG");
  harl.complain("WARNING");
  harl.complain("INFO");
  harl.complain("ERROR");
  harl.complain("NOTHING");
}
