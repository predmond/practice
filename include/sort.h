#ifndef sort_h
#define sort_h

#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include "heap.h"

void bubblesort(std::vector<int>::iterator begin,
                std::vector<int>::iterator end) {
  while (begin != --end) {
    for (std::vector<int>::iterator I = begin; I != end; ++I) {
      std::vector<int>::iterator I1 = I + 1;
      if (*I > *I1) std::swap(*I, *I1);
    }
  }
}

void mergesort(std::vector<int>::iterator begin,
               std::vector<int>::iterator end) {
  unsigned N = std::distance(begin, end);
  // Base cases.
  if (N < 2) return;
  if (N == 2) {
    end = begin + 1;
    if (*begin > *end) std::swap(*begin, *end);
    return;
  }
  // Divide.
  std::vector<int>::iterator M = begin + N / 2;
  mergesort(begin, M);
  mergesort(M, end);
  // Merge.
  std::vector<int> sorted;
  sorted.reserve(N);
  std::merge(begin, M, M, end, std::back_inserter(sorted));
  std::copy(sorted.begin(), sorted.end(), begin);
}

void heapsort(std::vector<int>::iterator begin,
              std::vector<int>::iterator end) {
  heap h;
  for (std::vector<int>::iterator I = begin; I != end; ++I)
    h.insert(*I);
  h.dump();
  while (!h.empty()) {
    *begin++ = h.extract_min();
    h.dump();
  }
  assert(begin == end);
}

#endif
