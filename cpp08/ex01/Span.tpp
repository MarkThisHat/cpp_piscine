/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:46:43 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/12 12:39:42 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Iterator>
void Span::addNumbers(Iterator first, Iterator last) {
  while (first != last) {
    addNumber(*first++);
  }
}
