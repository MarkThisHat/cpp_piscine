/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:10:24 by maalexan          #+#    #+#             */
/*   Updated: 2024/10/30 16:33:17 by maalexan         ###   ########.fr       */
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
void PmergeMe<Container, T, Allocator>::extractIndices(std::vector<int>& indices, const std::vector<Element<T> >& sorted) {
  typename std::vector<Element<T> >::const_iterator iter = sorted.begin();
  indices.clear();
  while (iter != sorted.end()) {
    indices.push_back(iter->oldIndex);
    iter++;
  }
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::mergeInsertionSort(Container<T, Allocator>& container, int containerSize) {
  if (containerSize < 1 || container.empty()) {
    throw std::invalid_argument("Invalid amount of elements to sort");
  } 
  typename Container<T, Allocator>::const_iterator iter = container.begin();
populateGroups(containerSize);
  clock_t inStart = clock();
  std::vector<Element<T> > elements;
  for (int i = 0; i < containerSize; i++) {
    elements.push_back(Element<T>(*iter++, i, 0));
  }
  double inTime = clockCalc(inStart, clock());

  clock_t sortStart = clock();
  std::vector<int> indexes;
  indexes = recursiveMerge(elements);
  double sortTime = clockCalc(sortStart, clock());

  clock_t outStart = clock();
  Container<T, Allocator> sortedContainer;
  for (int i = 0; i < containerSize; i++) {
    sortedContainer.push_back(elements[indexes[i]].value);
  }
  container = sortedContainer;
  double outTime = clockCalc(outStart, clock());
  clockLog(containerSize, sortTime, inTime, outTime);
}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<int> PmergeMe<Container, T, Allocator>::lastFew(std::vector<Element<T> >& input) {
  int size = input.size();
  std::vector<int> result;
  result.reserve(size);
  result.push_back(0);
  if (size == 1) return result;
  if (input[0].value < input[1].value) {
    result.push_back(1);
  } else {
    result.insert(result.begin(), 1);
  }
  return result;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
std::vector<int> PmergeMe<Container, T, Allocator>::recursiveMerge(std::vector<Element<T> >& input) {
  int size = input.size();
  if (size < 3) return lastFew(input);
  std::vector<int> indexes;

  std::vector<Element<T> > sorted;
  std::vector<Element<T> > unsorted;
  halver(input, sorted, unsorted);
  indexes = recursiveMerge(sorted);
  std::vector<Element<T> > reSorted;
  std::vector<Element<T> > reUnsorted;
  for (size_t i = 0; i < sorted.size(); i++) {
    reSorted.push_back(sorted[indexes[i]]);
    reUnsorted.push_back(unsorted[indexes[i]]);
  }
  if (sorted.size() != unsorted.size()) {
    reUnsorted.push_back(unsorted[sorted.size()]);
  }
  sorted = reSorted;
  sorted.insert(sorted.begin(), reUnsorted[0]);
  unsorted.clear();
  unsorted = organizeInGroups(reUnsorted);

  int inserted = 0;
  for (typename std::vector<Element<T> >::const_iterator iter = unsorted.begin(); iter != unsorted.end(); iter++) {
    binaryInsert(sorted, *iter, inserted++);
  }
  extractIndices(indexes, sorted);
  return indexes;
}

template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::halver(const std::vector<Element<T> >& container, std::vector<Element<T> >& high, std::vector<Element<T> >& low) {
  typename std::vector<Element<T> >::const_iterator iter = container.begin();
  typename std::vector<Element<T> >::const_iterator end = container.end();
  int i = 0;

  while (std::distance(iter, end) > 1) {
    T firstValue = iter->value;
    T secondValue = (iter + 1)->value;
    int firstIndex = iter->newIndex;
    int secondIndex = (iter + 1)->newIndex;

    if (firstValue > secondValue) {
      low.push_back(Element<T>(secondValue, i, secondIndex));
      high.push_back(Element<T>(firstValue, i, firstIndex));
    } else {
      low.push_back(Element<T>(firstValue, i, firstIndex));
      high.push_back(Element<T>(secondValue, i, secondIndex));
    }
    iter += 2;
    i++;
  }

  if (iter != end) {
    low.push_back(Element<T>(iter->value, i, iter->newIndex));
  }
}

/*
** Binary Insertion
*/
template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::binaryInsert(std::vector<Element<T> >& sorted, const Element<T>& element, int inserted) {
    int low = 0;
    int high = element.newIndex + inserted;

    // Perform binary search to find the correct position
    while (low < high) {
        int mid = (low + high) / 2;
        if (sorted[mid].value < element.value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    // Insert element at the calculated position
    sorted.insert(sorted.begin() + low, element);
}

/*
** Time tracking
*/
template <template <typename, typename> class Container, typename T, typename Allocator>
void PmergeMe<Container, T, Allocator>::clockLog(int range, double sortTime, double transferIn, double transferOut) const {
  double totalTime = sortTime + transferIn + transferOut;
  std::cout << std::fixed << std::setprecision(PRECISION)
            << "Time to process a range of " << range 
            << " elements with [<container>]-> " << totalTime
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
