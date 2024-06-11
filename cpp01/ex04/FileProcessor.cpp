/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:10:45 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/11 00:08:56 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

std::string FileProcessor::readFile(const std::string& filename) {
  std::ifstream file(filename.c_str());
  if (!file) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    return "";
  }
  std::string readFile;
  std::string line;
  while (std::getline(file, line)) {
      readFile += line;
      if (!file.eof()) {
      readFile += "\n";
    }
  }
  file.close();

  return readFile;
}

std::string FileProcessor::replaceFile(const std::string& content,
 const std::string& target, const std::string& replacement) {
  std::string modified = content;
  size_t position = 0;
  while ((position = modified.find(target, position)) != std::string::npos) {
      modified.replace(position, target.length(), replacement);
      position += replacement.length();
  }
  return modified;
}

bool FileProcessor::editFile(const std::string& filename,
 const std::string& content) {
  std::ofstream newFile(filename.c_str());
  if (!newFile) {
    std::cerr << "Failed to create file: " << filename << std::endl;
    return false;
  }
  newFile << content;
  newFile.close();
  std::cout << "Generated " << filename << " successfully." << std::endl;

  return true;
}

bool FileProcessor::processFile(const std::string &filename,
 const std::string &target, const std::string &replacement) {
  std::string wholeFile = readFile(filename);
  if (wholeFile.empty()) {
    return false;
  }
  std::string modified = replaceFile(wholeFile, target, replacement);
  std::string replacedFile = filename + ".replace";

  return editFile(replacedFile, modified);
}
