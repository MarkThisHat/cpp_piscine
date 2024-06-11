/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:40:50 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 23:29:04 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"
#include "Utils.hpp"

int main(int argc, char** argv) {
  if (argc != 4) {
    return Utils::argReject(argv[0]);
  }

  if (!FileProcessor::processFile(argv[1], argv[2], argv[3])) {
    return 1;
  }

  return 0;
}
