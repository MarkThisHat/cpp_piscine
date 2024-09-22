/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnyCouple.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:46:52 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/22 11:03:46 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "utils.hpp"

template<typename T1, typename T2 = int>
class AnyCouple {
 public:
  AnyCouple(T1 a, T2 b): dataOne(a), dataTwo(b) {}
  ~AnyCouple() {}
  AnyCouple(const AnyCouple& other): dataOne(other.dataOne), dataTwo(other.dataTwo) {}
  AnyCouple& operator=(const AnyCouple& other) {
    if (this != other) {
      dataOne = other.dataOne;
      dataTwo = other.dataTwo;
    }
    return *this;
  }

  T1 getFirst() const {
    return dataOne;
  }

  T2 getSecond() const {
    return dataTwo;
  }

  void displayData() const {
    printAny(dataOne);
    printAny(dataTwo);
  }

 private:
  T1 dataOne;
  T2 dataTwo;
};
