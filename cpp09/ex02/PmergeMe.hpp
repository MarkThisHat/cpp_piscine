/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/28 14:58:06 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <utility>

template <template <typename, typename> class Container, typename T, typename Allocator = std::allocator<T> >
class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void mergeInsertionSort(Container<T, Allocator>& container, int containerSize);

 private:
};

#include <iostream>
template<typename T>
void printer(const std::vector<std::pair<T, T> > vec) {
  typename std::vector<std::pair<T, T> >::const_iterator iter = vec.begin();
  while (iter != vec.end()) {
    std::cout << "<" << iter->first << ", " << iter->second << "> ";
    iter++;
  }
  std::cout << std::endl;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::mergeInsertionSort(Container<T, Allocator>& container, int containerSize) {
  if (container.empty() || containerSize < 1) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  }

  typename Container<T, Allocator>::const_iterator iter = container.begin();
  typename Container<T, Allocator>::const_iterator end = container.end();

  std::vector<std::pair<T, T> > elements;
  elements.reserve(containerSize / 2);
  T unpaired;

  while (std::distance(iter, end) > 1) {
    T first = *iter++;
    T second = *iter++;
    first < second ? 
      elements.push_back(std::make_pair(first, second)):
      elements.push_back(std::make_pair(second, first));
  }

  printer(elements);

  if (iter != end) {
    unpaired = *iter;
    std::cout << "unpaired: " << unpaired << std::endl;
  }
};


template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::PmergeMe() {}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::PmergeMe(const PmergeMe& other) {}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>& PmergeMe<Container, T, Allocator>::operator=(const PmergeMe& other) {
  if (this != &other) {
  }
  return *this;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::~PmergeMe() {}

/*
#include <vector>
#include <algorithm>
#include <utility>

// Helper to create sorted pairs
void createPairs(const std::vector<int>& arr, std::vector<std::pair<int, int> >& pairs,
                 std::vector<int>& largerElements, std::pair<bool, int>& unpaired) {
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] < arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
        largerElements.push_back(pairs.back().second); // Collect the larger element
    }

    if (arr.size() % 2 != 0) {
        unpaired.first = true;
        unpaired.second = arr.back();
    }
}

// Helper to insert elements using binary search
void insertElements(const std::vector<std::pair<int, int> >& pairs, std::vector<int>& sortedSequence,
                    const std::pair<bool, int>& unpaired) {
    sortedSequence.push_back(pairs[0].first); // Insert the smallest of the first pair

    for (size_t i = 1; i < pairs.size(); ++i) {
        int smallerElement = pairs[i].first;
        auto pos = std::lower_bound(sortedSequence.begin(), sortedSequence.end(), smallerElement);
        sortedSequence.insert(pos, smallerElement);
    }

    if (unpaired.first) {
        auto pos = std::lower_bound(sortedSequence.begin(), sortedSequence.end(), unpaired.second);
        sortedSequence.insert(pos, unpaired.second);
    }
}

// Main recursive Merge-Insertion Sort function
void mergeInsertSort(std::vector<int>& arr, size_t arrSize) {
    if (arrSize <= 2) {
        if (arrSize == 2 && arr[0] > arr[1]) {
            std::swap(arr[0], arr[1]);
        }
        return;
    }

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> largerElements;
    std::pair<bool, int> unpaired(false, 0);

    // Step 1: Pair and sort each pair
    createPairs(arr, pairs, largerElements, unpaired);

    // Step 2: Recursively sort larger elements
    mergeInsertSort(largerElements, arrSize / 2);

    // Step 3: Insert smaller elements and unpaired element
    std::vector<int> sortedSequence;
    insertElements(pairs, sortedSequence, unpaired);

    // Step 4: Merge sorted sequences back into original array
    size_t index = 0;
    for (size_t i = 0; i < sortedSequence.size(); ++i, ++index) {
        arr[index] = sortedSequence[i];
    }
    for (size_t i = 0; i < largerElements.size(); ++i, ++index) {
        arr[index] = largerElements[i];
    }
}



Merge-insertion sort performs the following steps, on an input X of n elements:[6]

1   Group the elements of X into ⌊ n / 2 ⌋ pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.

2   Perform ⌊ n / 2 ⌋ comparisons, one per pair, to determine the larger of the two elements in each pair.

3   Recursively sort the ⌊ n / 2 ⌋ larger elements from each pair,
    creating a sorted sequence S of ⌊ n / 2 ⌋ of the input elements,
    in ascending order, using the merge-insertion sort.

4   Insert at the start of S the element that was paired with the first and smallest element of S

5   Insert the remaining ⌈ n / 2 ⌉ − 1 elements of X ∖ S into S one at a time,
    with a specially chosen insertion ordering described below.
    Use binary search in subsequences of S (as described below) to determine the
    position at which each element should be inserted.

The algorithm is designed to take advantage of the fact that the binary searches used to insert elements into S are most efficient (from the point of view of worst case analysis) when the length of the subsequence that is searched is one less than a power of two. This is because, for those lengths, all outcomes of the search use the same number of comparisons as each other.[1] To choose an insertion ordering that produces these lengths, consider the sorted sequence S after step 4 of the outline above (before inserting the remaining elements), and let x i denote the ith element of this sorted sequence. Thus,

S = ( x 1 , x 2 , x 3 , … ) , 
where each element x i with i ≥ 3 is paired with an element y i < x i that has not yet been inserted. (There are no elements y 1 or y 2 because x 1 and x 2 were paired with each other.) If n is odd, the remaining unpaired element should also be numbered as y i with i larger than the indexes of the paired elements. Then, the final step of the outline above can be expanded into the following steps:[1][2][3][4]

Partition the uninserted elements y i into groups with contiguous indexes. There are two elements y 3 and y 4 in the first group, and the sums of sizes of every two adjacent groups form a sequence of powers of two. Thus, the sizes of groups are: 2, 2, 6, 10, 22, 42, ...
Order the uninserted elements by their groups (smaller indexes to larger indexes), but within each group order them from larger indexes to smaller indexes. Thus, the ordering becomes

y 4 , y 3 , y 6 , y 5 , y 12 , y 11 , y 10 , y 9 , y 8 , y 7 , y 22 , y 21 …

Use this ordering to insert the elements y i into S  For each element y i, use a binary search from the start of S up to but not including x i to determine where to insert y i.
*/


