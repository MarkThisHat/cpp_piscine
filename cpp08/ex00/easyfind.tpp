/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:12:35 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/01 13:34:57 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <sstream>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it = std::find(container.begin(), container.end(), value);

  if (it == container.end()) {
    std::ostringstream oss;
    oss << "Couldn't find value " << value;
    throw std::runtime_error(oss.str());
  }

  return it;
}