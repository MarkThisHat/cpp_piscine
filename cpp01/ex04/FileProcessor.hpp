/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:09:09 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 19:00:03 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <sstream>

class FileProcessor {
 public:
  static bool processFile(
    const std::string& filename,
    const std::string& target,
    const std::string& replacement);
};
