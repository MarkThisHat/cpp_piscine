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
void printElement(const std::pair<T, int>& element) {
    std::cout << "<value: " << element.first << ", index: " << element.second << ">";
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

template <typename T>
void bostaryInsert(std::vector<std::pair<T, int> >& sorted, const std::pair<T, int>& element) {
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

  void newMergeInsertionSort(Container<T, Allocator>& container, int containerSize);
 private:
  std::vector<T> merge(std::vector<T>& container, int size);
  void distribute(const std::vector<T>& container, std::vector<T>& high, std::vector<T>& low);
  std::vector<T> lastRecursion(std::vector<T>& container, int size);
  void binaryInsert(std::vector<T>& sorted, const T& element);
  void clockLog(int range, double sortTime) const;
  void clockLog(int range, double sortTime, double transferIn, double transferOut) const;
  double clockCalc(clock_t start, clock_t finish) const;

  std::vector<int> recursiveMerge(std::vector<std::pair<T, int> >& input);
  
  void halver(const std::vector<std::pair<T, int> >& container, std::vector<std::pair<T, int> >& high, std::vector<std::pair<T, int> >& low);

  std::vector<int> lastFew(std::vector<std::pair<T, int> >& input);
  void extractIndices(std::vector<int>& indices, const std::vector<std::pair<T, int> >& sorted);
};

#include "PmergeMe.tpp"

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::extractIndices(std::vector<int>& indices, const std::vector<std::pair<T, int> >& sorted) {
  typename std::vector<std::pair<T, int> >::const_iterator iter = sorted.begin();
  indices.clear();
std::cout << "mothafucka \n";
printElements(sorted);
  while (iter != sorted.end()) {
/*  std::cout << "gonna take out the index of ";
    printElement(*iter);*/
    indices.push_back(iter->second);
//    std::cout << " which is " << iter->second << std::endl;
    iter++;
  }
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::newMergeInsertionSort(Container<T, Allocator>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 
  typename Container<T, Allocator>::const_iterator iter = container.begin();

  std::vector<std::pair<T, int> > elements;
  for (int i = 0; i < containerSize; i++) {
    elements.push_back(std::make_pair(*iter++, i));
  }

  std::vector<int> indexes;
  indexes = recursiveMerge(elements);
  printIndexes(indexes);
}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<int> PmergeMe<Container, T, Allocator>::lastFew(std::vector<std::pair<T, int> >& input) {
  int size = input.size();
  if (size == 1) {
    throw std::invalid_argument("Size 1 should not be in last few");
  }
  std::vector<int> result;
  if (input[0].first < input[1].first) {
    result.push_back(input[0].second);
    result.push_back(input[1].second);
  } else {
    result.push_back(input[0].second);
    result.push_back(input[1].second);
  }
  if (size == 3) {
    if (input[2].first < input[result[0]].first) {
      result.insert(result.begin(), input[2].second);
    } else if (input[2].first > input[result[1]].first) {
      result.push_back(input[2].second);
    } else {
      result.insert(result.begin() + 1, input[2].second);
    }
  }
  return result;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<int> PmergeMe<Container, T, Allocator>::recursiveMerge(std::vector<std::pair<T, int> >& input) {
  int size = input.size();
  std::cout << "Entering recursive merge with: " << std::endl;
  printElements(input);
  if (size < 4) return lastFew(input);
  std::vector<int> indexes;

  std::vector<std::pair<T, int> > sorted;
  std::vector<std::pair<T, int> > unsorted;
  halver(input, sorted, unsorted);
  indexes = recursiveMerge(sorted);
  std::vector<std::pair<T, int> > reSorted;
  std::vector<std::pair<T, int> > reUnsorted;
  for (size_t i = 0; i < sorted.size(); i++) {
    reSorted.push_back(sorted[indexes[i]]);
    reUnsorted.push_back(unsorted[indexes[i]]);
  }
  if (sorted.size() != unsorted.size()) {
    reUnsorted.push_back(unsorted[sorted.size()]);
  }
  sorted = reSorted;
  unsorted = reUnsorted;

//  sorted.insert(sorted.begin(), unsorted[0]);
  for (typename std::vector<std::pair<T, int> >::const_iterator iter = unsorted.begin(); iter != unsorted.end(); iter++) {
    bostaryInsert(sorted, *iter);
  }
  std::cout << "fa\n";
  printElements(sorted);
  printElements(input);
  std::cout << "fu" << std::endl;
  extractIndices(indexes, sorted);
  return indexes;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::halver(const std::vector<std::pair<T, int> >& container, std::vector<std::pair<T, int> >& high, std::vector<std::pair<T, int> >& low) {
  typename std::vector<std::pair<T, int> >::const_iterator iter = container.begin();
  typename std::vector<std::pair<T, int> >::const_iterator end = container.end();
  int i = 0;
  
  while (std::distance(iter, end) > 1) {
    T firstValue = iter->first;
    T secondValue = (iter + 1)->first;

    if (firstValue > secondValue) {
      low.push_back(std::make_pair(secondValue, i));
      high.push_back(std::make_pair(firstValue, i));
    } else {
      low.push_back(std::make_pair(firstValue, i));
      high.push_back(std::make_pair(secondValue, i));
    }
    iter += 2;
    i++;
  }

  if (iter != end) {
    low.push_back(std::make_pair(iter->first, i));
  }
}
