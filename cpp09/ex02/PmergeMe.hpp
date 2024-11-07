/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/30 19:56:44 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

# ifndef DEBUG
#  define DEBUG 0
# endif
# ifndef PRINTABLE
#  define PRINTABLE 15
# endif
# define PRECISION 0

template <typename T>
struct Element {
    T value;
    int newIndex;
    int oldIndex;

    Element(const T& val, int newIndex, int oldIndex)
        : value(val), newIndex(newIndex), oldIndex(oldIndex) {}
  };

template <typename T>
void printElement(const Element<T>& element) {
    std::cout << "<value: " << element.value << ", new index: " << element.newIndex << ", old index: " << element.oldIndex <<">";
}

template <typename T>
void printElements(const std::vector<T>& elements) {
    for (typename std::vector<T>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        printElement(*it);
        std::cout << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void printIndexes(const std::vector<T>& elements) {
    for (typename std::vector<T>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
/* jacobostal


// Helper function to generate the Jacobsthal-based group sizes
inline std::vector<int> generateGroupSizes(int totalElements) {
    std::vector<int> groupSizes;
    int currentSize = 2;
    int sum = 0;

    while (sum < totalElements) {
        groupSizes.push_back(currentSize);
        sum += currentSize;

        // Alternate between doubling and adding 2
        currentSize = (groupSizes.size() % 2 == 1) ? currentSize * 2 + 2 : currentSize * 2;
    }

    return groupSizes;
}

// Function to partition and order the unsorted elements based on Jacobsthal group sizes
template <typename T>
std::vector<std::pair<T, int> > partitionAndOrder(const std::vector<std::pair<T, int> >& unsorted) {
    std::vector<int> groupSizes = generateGroupSizes(unsorted.size());
    std::vector<std::pair<T, int> > orderedUnsorted;

    size_t pos = 0;
    for (size_t i = 0; i < groupSizes.size() && pos < unsorted.size(); ++i) {
        int groupSize = groupSizes[i];

        // Extract the group and manually reverse its order
        std::vector<std::pair<T, int> > group;
        for (int j = 0; j < groupSize && pos < unsorted.size(); ++j, ++pos) {
            group.push_back(unsorted[pos]);
        }

        // Insert the group in reverse order into orderedUnsorted
        for (int k = group.size() - 1; k >= 0; --k) {
            orderedUnsorted.push_back(group[k]);
        }
    }

    return orderedUnsorted;
}

// Function to perform binary insertion
template <typename T>
void binaryInsert(std::vector<std::pair<T, int> >& sorted, const std::pair<T, int>& element) {
    int low = 0;
    int high = sorted.size();

    // Perform binary search to find the correct position
    while (low < high) {
        int mid = (low + high) / 2;
        if (sorted[mid].first < element.first) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    // Insert element at the calculated position
    sorted.insert(sorted.begin() + low, element);
}

// Function to perform the Jacobsthal-based insertion of unsorted into sorted
template <typename T>
void jacobsthalInsert(std::vector<std::pair<T, int> >& sorted, const std::vector<std::pair<T, int> >& unsorted) {
    // Partition and order the unsorted elements according to Jacobsthal sequence
    std::vector<std::pair<T, int> > orderedUnsorted = partitionAndOrder(unsorted);

    // Insert each element from orderedUnsorted into sorted using binary search
    for (typename std::vector<std::pair<T, int> >::const_iterator it = orderedUnsorted.begin(); it != orderedUnsorted.end(); ++it) {
        binaryInsert(sorted, *it);
    }
}

*/


//Actual class
template <template <typename, typename> class Container, typename T, typename Allocator = std::allocator<T> >
class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void mergeInsertionSort(Container<T, Allocator>& container, int containerSize);
  Container<T, Allocator> mergeInsertionSort(const Container<T, Allocator>& container, int containerSize) const;
  void printContainer(const Container<T, Allocator>& container) const;
  bool isSorted(const Container<T, Allocator>& container, const std::string containerName) const;

 private:

  void binaryInsert(std::vector<Element<T> >& sorted, const Element<T>& element);
  void clockLog(int range, double sortTime) const;
  void clockLog(int range, double sortTime, double transferIn, double transferOut) const;
  double clockCalc(clock_t start, clock_t finish) const;

  std::vector<int> recursiveMerge(std::vector<Element<T> >& input);

  void halver(const std::vector<Element<T> >& container, std::vector<Element<T> >& high, std::vector<Element<T> >& low);

  std::vector<int> lastFew(std::vector<Element<T> >& input);
  void extractIndices(std::vector<int>& indices, const std::vector<Element<T> >& sorted);

};

#include "PmergeMe.tpp"

