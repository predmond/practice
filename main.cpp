#include "sort.h"
#include "misc.h"

int main(int argc, char *argv[]) {
  std::vector<int> A(1<<3);
  for (unsigned i = 0; i < A.size(); ++i)
    A[i] = std::rand() % 256;

#if 0
  //print(A.begin(), A.end(), "Input");
  mergesort(A.begin(), A.end());
  print(A.begin(), A.end(), "Output");

  print(A.begin(), A.end(), "Not reversed");
  reverse(A);
  print(A.begin(), A.end(), "Reverse");
#endif

#if 0
  heap h;
  h.insert(13);
  h.insert(11);
  h.insert(9);
  h.insert(12);
  h.insert(4);
  h.insert(9);
  h.insert(8);
  h.insert(4);
  h.insert(4);
  h.dump();
  std::cout << "min = " << h.extract_min() << std::endl;
  h.dump();
#endif

  print(A.begin(), A.end(), "Input");
//  heapsort(A.begin(), A.end());
  selectionsort(A.begin(), A.end());
  print(A.begin(), A.end(), "Output");
}
