#include <stdexcept>
#include <iostream>
#include "d64_q2b_vector_block_swap_cp_vector_template.h"
#include "d64_q2b_vector_block_swap_method.h"


int main() {
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);
    CP::vector<int> v;
    int round,n;
    std::cin >> n;
    for (int i = 0;i < n;i++) {
      int x;
      std::cin >> x;
      v.push_back(x);
    }

    int a,b,m;
    std::cin >> a >> b >> m;
    bool result = v.block_swap(v.begin() + a, v.begin() + b,m);
    std::cout << "result is " << result << std::endl;
    std::cout << "Size of v is " << v.size() << std::endl;
    std::cout << "v: ";
    for (auto &x : v) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
}
