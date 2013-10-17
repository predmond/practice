#ifndef misc_h
#define misc_h

void print(std::vector<int>::iterator begin,
           std::vector<int>::iterator end,
           const std::string &text) {
  std::cout << text << ": ";
  for (; begin != end; ++begin)
    std::cout << *begin << " ";
  std::cout << std::endl;
}

//void reverse(std::vector<int> &A) {
//  unsigned N = A.size() / 2;
//  for (unsigned i = 0, j = A.size() - 1; i < N; ++i, --j)
//    std::swap(A[i], A[j]);
//}


#endif
