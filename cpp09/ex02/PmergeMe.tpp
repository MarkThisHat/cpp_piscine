/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/30 15:45:59 by maalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::PmergeMe() {}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::PmergeMe(const PmergeMe& other) {
  groupSizes = other.groupSizes;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>& PmergeMe<Container, T, Allocator>::operator=(const PmergeMe& other) {
  if (this != &other) {
    groupSizes = other.groupSizes;
  }
  return *this;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
PmergeMe<Container, T, Allocator>::~PmergeMe() {}

/*
** Merge Sorting
*/
template <template <typename, typename> class Container, typename T, typename Allocator>
Container<T, Allocator> PmergeMe<Container, T, Allocator>::mergeInsertionSort(const Container<T, Allocator>& container, int containerSize) const {
  Container<T, Allocator> newContainer = container;
  const_cast<PmergeMe*>(this)->mergeInsertionSort(newContainer, containerSize);
  return newContainer;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::mergeInsertionSort(Container<T, Allocator>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 
  calculateGroupSizes(containerSize);
  typename Container<T, Allocator>::const_iterator iter = container.begin();
  typename Container<T, Allocator>::const_iterator end = container.end();

  std::vector<T> elements;
  clock_t inStart = clock();
  elements.reserve(containerSize);
  while (iter != end) {
    elements.push_back(*iter++);
  }
  double inTime = clockCalc(inStart, clock());

  clock_t sortStart = clock();
  elements = merge(elements, containerSize);
  double sortTime = clockCalc(sortStart, clock());
  
  clock_t outStart = clock();
  container.clear();
  container.insert(container.end(), elements.begin(), elements.end());
  double outTime = clockCalc(outStart, clock());

  clockLog(containerSize, sortTime, inTime, outTime);
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
  if (DEBUG > 0) {
    for (typename std::vector<T>::iterator iter = unsorted.begin(); iter != unsorted.end(); iter++) {
      binaryInsert(sorted, *iter);
    }
  } else {
    orderedInsertion(sorted, unsorted);
  }
  return sorted;
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

/*
** Binary Insertion
*/
template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::binaryInsert(std::vector<T>& sorted, const T& element) {
  specializedBinaryInsert(sorted, element, sorted.end());
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::specializedBinaryInsert(std::vector<T>& sorted, const T& element, typename std::vector<T>::iterator end) {
  typename std::vector<T>::iterator low = sorted.begin();
  typename std::vector<T>::iterator high = end;

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
void PmergeMe<Container, T, Allocator>::orderedInsertion(std::vector<T>& sorted, std::vector<T>& unsorted) {
  int unsortedSize = unsorted.size();
  int elementsRemaining = unsortedSize;
  int index = 0;

  for (std::vector<int>::const_iterator it = groupSizes.begin(); elementsRemaining > 0 && it != groupSizes.end(); it++) {
    int groupSize = std::min(*it, elementsRemaining); 
    for (int i = groupSize - 1; i >= 0 && index < unsortedSize; i--, index++) {
      specializedBinaryInsert(sorted, unsorted[index], sorted.end());
    }
    elementsRemaining -= groupSize;
  }
}

/*
** Generation of 2 powered array to optimize comparations
*/
template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::printGroupSizes(int sum) const {
  std::vector<int>::const_iterator iter = groupSizes.begin();
  while (iter != groupSizes.end()) {
    std::cout << *iter++ << " ";
  }
  std::cout << "sum: " << sum;
  std::cout << "groups size " << groupSizes.size() << std::endl;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::calculateGroupSizes(int n) {
  groupSizes.clear();
  int lastSize = 2;
  int sum = 0;
  while (sum < n) {
    groupSizes.push_back(lastSize);
    sum += lastSize;       
    if (groupSizes.size() % 2 == 0) {
        lastSize *= 2;
    }
  }
  if (sum > n) {
      groupSizes.back() -= (sum - n);
  }
  if (DEBUG == 2) printGroupSizes(sum);
}

/*
** Time tracking
*/
template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::clockLog(int range, double sortTime, double transferIn, double transferOut) const {
  double totalTime = sortTime + transferIn + transferOut;
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time to process a range of " << range 
            << " elements with [template] -> " << totalTime
            << "µs (sort: " << sortTime << "µs + in: " << transferIn
            << "µs + out: " << transferOut << "µs)"<< std::endl;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
double PmergeMe<Container, T, Allocator>::clockCalc(clock_t start, clock_t finish) const {
  return double(finish - start) * 1000000 / CLOCKS_PER_SEC;
}

/*
**  Sorting validation
*/
template <template <typename, typename> class Container, typename T, typename Allocator>
bool PmergeMe<Container, T, Allocator>::isSorted(const Container<T, Allocator>& container, const std::string containerName) const {
  if (container.size() < 2) return true;

  typename Container<T, Allocator>::const_iterator next = container.begin();
  typename Container<T, Allocator>::const_iterator iter = next++;

  while (next != container.end()) {
    if (*iter++ > *next++) {
      std::cerr << "Container " << containerName << " is not sorted" << std::endl;
      return false;
    }
  }
  return true;
}

/*
** Container printer
*/
template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::printContainer(const Container<T, Allocator>& container) const {
  typename Container<T, Allocator>::const_iterator iter = container.begin();
  const int totalItems = container.size();

  int i = 0;
  while (i < PRINTABLE - 3 && iter != container.end()) {
    std::cout << *iter++ << " ";
    i++;
  }
  if (totalItems > PRINTABLE) {
    std::cout << "[...] ";
  }
  if (totalItems > PRINTABLE - 3) {
    iter = container.end();
    std::advance(iter, -3);

    while (iter != container.end()) {
        std::cout << *iter++ << " ";
    }
  }
  std::cout << std::endl;
}
