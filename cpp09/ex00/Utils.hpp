/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:20:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/17 16:51:09 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <stdexcept>

class Utils {
 public:
  static const std::string ARG_REJECT;
  static int argReject(const std::string& programName);
  static std::ifstream fileOpen(const std::string& filePath);
  static bool fileValidate(const std::ifstream file);

 private:
  Utils();
  Utils(const Utils& other);
  Utils& operator=(const Utils& other);
  ~Utils();
};
