/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:10:45 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 19:24:01 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

bool FileProcessor::processFile(const std::string &filename,
                                const std::string &target,
                                const std::string &replacement) {
  std::ifstream file(filename.c_str());
  if (!file) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    return false;
  }

  std::string wholeFile;
  std::string line;
  while (std::getline(file, line)) {
      wholeFile += line + "\n";
  }
  file.close();

  size_t position = 0;

  while ((position = wholeFile.find(target, position)) != std::string::npos) {
    wholeFile.erase(position, target.length());
    wholeFile.insert(position, replacement);
    position += replacement.length();
  }

  std::string replacedFile = filename + ".replacement";
  std::ofstream newFile(replacedFile.c_str());
  if (!newFile) {
    std::cerr << "Failed to create file: " << replacedFile << std::endl;
    return false;
  }
  newFile << wholeFile;
  newFile.close();

  return true;
}