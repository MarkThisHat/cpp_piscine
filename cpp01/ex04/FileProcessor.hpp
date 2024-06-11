/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:09:09 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/11 08:43:58 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <ostream>
#include <iostream>

class FileProcessor {
 public:
  static bool processFile(
    const std::string &filename,
    const std::string &target,
    const std::string &replacement);
  static std::string replaceFile(
    const std::string &content,
    const std::string &target,
    const std::string &replacement);
  static bool produceFile(
    const std::string &filename,
    const std::string &content);
  static std::string readFile(const std::string &filename);
};
