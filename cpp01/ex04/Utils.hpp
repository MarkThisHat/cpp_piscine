/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:20:15 by maalexan          #+#    #+#             */
/*   Updated: 2024/06/10 16:36:12 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>

class Utils {
 public:
  static const std::string ARG_REJECT;

  static int argReject(const std::string& programName) {
    std::cerr << "Usage: " << programName  << ARG_REJECT << std::endl;
    return 1;
  }
};

const std::string Utils::ARG_REJECT = " [file to open] [string to FIND] [string to REPLACE]";
