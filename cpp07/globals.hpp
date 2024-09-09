/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:46:12 by maalexan          #+#    #+#             */
/*   Updated: 2024/09/09 20:52:38 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
const T& min(T& a, T& b) {
  if (a < b) return a;
  return b;
}

template <typename T>
const T& max(T& a, T& b) {
  if (a > b) return a;
  return b;
}
