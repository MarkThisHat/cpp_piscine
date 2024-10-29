/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:05:38 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/29 19:19:47 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

template<>
clock_t PmergeMe<std::vector, int>::clockStart() {
    return clock();
}

template<>
double PmergeMe<std::vector, int>::clockEnd(clock_t startTime) {
    clock_t endTime = clock();
    double timeTakenUs = double(endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(6) 
              << "Time taken for std::vector : " << timeTakenUs << " µs" << std::endl;
    return timeTakenUs;
}

template<>
clock_t PmergeMe<std::list, int>::clockStart() {
    return clock();
}

template<>
double PmergeMe<std::list, int>::clockEnd(clock_t startTime) {
    clock_t endTime = clock();
    double timeTakenUs = double(endTime - startTime) * 1000000 / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(6) 
              << "Time taken for std::vector : " << timeTakenUs << " µs" << std::endl;
    return timeTakenUs;
}
