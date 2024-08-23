/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:26:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/08/23 12:05:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat defaultConstructor();
    PRINT(BLUE, defaultConstructor);
  } catch (std::exception& e) {
    PERR(BOLD BLACK BG_RED, e.what());
  }
}
