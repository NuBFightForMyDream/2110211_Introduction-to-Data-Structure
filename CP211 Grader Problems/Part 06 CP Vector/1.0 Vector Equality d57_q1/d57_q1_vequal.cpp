#include <stdexcept>
#include <iostream>
#include "d57_q1_vequal_cp_vector_template.h"
#include "d57_q1_vequal_operator_equal.h"

bool equal(CP::vector<int> &a,CP::vector<int> &b) {
  if (a.size() != b.size()) return false;
  for (size_t i = 0;i < a.size();i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int main() {
  int n,m;
  std::cin >> n >> m;

  //read input
  CP::vector<int> a,b;
  while (n--) {
    int tmp;
    std::cin >> tmp;
    a.push_back(tmp);
  }
  while (m--) {
    int tmp;
    std::cin >> tmp;
    b.push_back(tmp);
  }

  //check
  std::cout << (a == b) << std::endl;
  std::cout << (b == a) << std::endl;
}

