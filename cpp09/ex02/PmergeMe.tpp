/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/29 19:05:14 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::PmergeMe() {}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::PmergeMe(const PmergeMe& other) {}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>& PmergeMe<Container, T, Allocator>::operator=(const PmergeMe& other) {
  return *this;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::~PmergeMe() {}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::binary_insert(std::vector<T>& sorted, const T& element) {
  typename std::vector<T>::iterator low = sorted.begin();
  typename std::vector<T>::iterator high = sorted.end();
  
  while (low < high) {
    typename std::vector<T>::iterator mid = low + (high - low) / 2;
    if (element < *mid) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  sorted.insert(low, element);
}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<T> PmergeMe<Container, T, Allocator>::lastRecursion(std::vector<T>& container, int size) {
  std::vector<T> last;
  last.reserve(size);
  if (size == 1) last.push_back(container[0]);
  if (size == 2) {
    if(container[0] > container[1]) {         
      last.push_back(container[1]);
      last.push_back(container[0]);
    } else {
      last.push_back(container[0]);
      last.push_back(container[1]);
    }
  }
  return last;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::distribute(const std::vector<T>& container, std::vector<T>& high, std::vector<T>& low) {
  typename std::vector<T>::const_iterator iter = container.begin();
  typename std::vector<T>::const_iterator end = container.end();

  while (std::distance(iter, end) > 1) {
    T first = *iter++;
    T second = *iter++;
    if (first > second) {
      low.push_back(second);
      high.push_back(first);
    } else {
      low.push_back(first);
      high.push_back(second);
    }
  }
  if (iter != end) {
    low.push_back(*iter);
  }
}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<T> PmergeMe<Container, T, Allocator>::merge(std::vector<T>& container, int size) {
  if (size < 3) return lastRecursion(container, size);
  int newSize = size / 2;
  std::vector<T> sorted;
  std::vector<T> unsorted;

  sorted.reserve(size);
  unsorted.reserve(size - newSize);
  distribute(container, sorted, unsorted);
  sorted = merge(sorted, newSize); 
  for (typename std::vector<T>::iterator iter = unsorted.begin(); iter != unsorted.end(); ++iter) {
    binary_insert(sorted, *iter);
  }
  return sorted;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::mergeInsertionSort(Container<T, Allocator>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 
  typename Container<T, Allocator>::const_iterator iter = container.begin();
  typename Container<T, Allocator>::const_iterator end = container.end();

  clock_t startTime = clockStart();

  std::vector<T> elements;
  elements.reserve(containerSize);
  while (iter != end) {
    elements.push_back(*iter++);
  }
  elements = merge(elements, containerSize);
  container.clear();
  container.insert(container.end(), elements.begin(), elements.end());
  clockEnd(startTime);
}

template <template <typename, typename> class Container, typename T, typename Allocator>
Container<T, Allocator> PmergeMe<Container, T, Allocator>::mergeInsertionSort(const Container<T, Allocator>& container, int containerSize) const {
  Container<T, Allocator> newContainer = container;
  const_cast<PmergeMe*>(this)->mergeInsertionSort(newContainer, containerSize);

  return newContainer;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::printContainer(const Container<T, Allocator>& container) const {
    typename Container<T, Allocator>::const_iterator iter = container.begin();
    while (iter != container.end()) {
      std::cout << *iter++ << " ";
    }
    std::cout << std::endl;
}
