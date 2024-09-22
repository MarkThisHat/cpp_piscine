/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:21:27 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/22 11:25:41 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "utils.hpp"
#include "AnyCouple.hpp"

void callDisplayData(AnyCouple<float, int>& object) {
    object.displayData();
}

int main() {
  int arrayOfInts[] = { 1, 3, 5};
  float arrayOfFloats[] = { 1.1, 3.3, 5.5, 7.7};
  std::string arrayOfStrings[] = {"Hello", "darkness", "my", "old", "friend"};

  AnyCouple<float, int> arrayOfAnys[3] = {
    AnyCouple<float, int>(0.1, 7),
    AnyCouple<float, int>(0.3, 9),
    AnyCouple<float, int>(0.5, 11)
  };

  iter(arrayOfInts, sizeof(arrayOfInts) / sizeof(arrayOfInts[0]), printAny);
  iter(arrayOfFloats, sizeof(arrayOfFloats) / sizeof(arrayOfFloats[0]), printAny);
  iter(arrayOfStrings, sizeof(arrayOfStrings) / sizeof(arrayOfStrings[0]), printAny);
  iter(arrayOfAnys, sizeof(arrayOfAnys) / sizeof(arrayOfAnys[0]), callDisplayData);
}
