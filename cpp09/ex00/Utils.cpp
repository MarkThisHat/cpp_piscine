/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:20:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/17 16:52:10 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

const std::string Utils::ARG_REJECT = "[Database with prices | dates]";

Utils::Utils() {
  throw std::runtime_error("Instantiation of a static Utils class");
}
Utils::Utils(const Utils& other) {
  throw std::runtime_error("Instantiation of a static Utils class");
}
Utils& Utils::operator=(const Utils& other) {
  throw std::runtime_error("Instantiation of a static Utils class");
}
Utils::~Utils() {};

int Utils::argReject(const std::string& programName) {
  std::cerr << "Usage: " << programName  << ARG_REJECT << std::endl;
  return 1;
}

std::ifstream Utils::fileOpen(const std::string& filePath) {
  std::ifstream fileStream(filePath);
  return fileStream;
}

bool Utils::fileValidate(const std::ifstream file) {
  if (!file.is_open()) {
    std::cerr << "Error: opening file" << std::endl;
    return false;
  }
  if (file.fail()) {
    std::cerr << "Error: File stream in bad state" << std::endl;
    return false;
  }
  if (file.bad()) {
    std::cerr << "Error: Fatal I/O error in the file stream" << std::endl;
    return false;
  }
  return true;
}
