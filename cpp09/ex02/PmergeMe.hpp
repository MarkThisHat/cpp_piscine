/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/25 21:08:43 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <utility>

template <typename T, template <typename> class Container>
class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void mergeInsertionSort(Container<T>& container, int containerSize);

 private:
};

template <typename T, template <typename> class Container>
void PmergeMe<T, Container>::mergeInsertionSort(Container<T>& container, int containerSize) {
  Container<T>::const_iterator iter;
  std::vector<std::pair<T, T> elements;
  std::pair<bool, T> unpaired;
  
};



/*
#include <vector>
#include <algorithm>
#include <utility>

// Helper to create sorted pairs
void createPairs(const std::vector<int>& arr, std::vector<std::pair<int, int>>& pairs,
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
void insertElements(const std::vector<std::pair<int, int>>& pairs, std::vector<int>& sortedSequence,
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

*/