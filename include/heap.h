#ifndef heap_h
#define heap_h

#include <vector>
#include <iostream>
#include <cassert>

struct heap {
  heap() {
    m_heap.reserve(1 << 8);
  }

  bool empty() const { return m_heap.empty(); }

  void insert(int value) {
    m_heap.push_back(value);
    bubble_up(m_heap.size() - 1);
  }

  int extract_min() {
    assert(!empty());
    int min = m_heap.front();
    std::swap(m_heap.front(), m_heap.back());
    m_heap.resize(m_heap.size() - 1);
    bubble_down(0);
    return min;
  }

  void dump() {
    int next = 1;
    std::cout << "heap size " << m_heap.size() << std::endl;
    for (unsigned i = 0, n = 0; i < m_heap.size(); ++i, ++n) {
      if (n == next) {
        std::cout << std::endl;
        next *= 2;
        n = 0;
      }
      if (n == 0)
        std::cout << "  ";
      std::cout << m_heap[i] << " ";
    }
    std::cout << std::endl;
  }

private:
  void bubble_up(int i) {
    if (i == 0) return;
    int p = parent(i);
    if (m_heap[i] < m_heap[p]) {
      std::swap(m_heap[i], m_heap[p]);
      bubble_up(p);
    }
  }

  void bubble_down(int i) {
    int min = i * 2 + 1;
    int other = min + 1;

    if (min >= m_heap.size())
      return;

    if (other < m_heap.size())
      if (m_heap[other] < m_heap[min])
        std::swap(other, min);

    if (m_heap[i] <= m_heap[min])
      return;
    std::swap(m_heap[i], m_heap[min]);
    bubble_down(min);
  }

  int parent(int i) const {
    return i / 2;
  }
  int child(int i) const {
    return i * 2 + 1;
  }


  std::vector<int> m_heap;
};

#endif // heap_h
