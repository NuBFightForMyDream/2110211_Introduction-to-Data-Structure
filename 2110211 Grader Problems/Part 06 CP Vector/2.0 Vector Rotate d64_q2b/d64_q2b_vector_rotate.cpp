#include <stdexcept>
#include <iostream>
#include <string>
#include <cassert>
#include "d64_q2b_vector_rotate_cp_vector_template.h"
#include "d64_q2b_vector_rotate_method.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int n,a,b;
  size_t k;
  cin >> n >> a >> b >> k;
  CP::vector<int> v(n);
  for (int i = 0;i < n;i++) v[i] = i;
  v.rotate(v.begin() + a, v.begin() + b,k);
  for (auto &x : v) cout << x << " ";
  cout << endl;
}
