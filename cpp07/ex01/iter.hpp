/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:51:00 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/13 11:58:36 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter(T* array, int arrayLength, void (*function)(T&)) {
  for (int i = 0; i < arrayLength; i++) {
    function(array[i]);
  }
}

template <typename T, typename F>
void iter(T* array, int arrayLength, F function) {
  for (int i = 0; i < arrayLength; i++) {
    function(array[i]);
  }
}
