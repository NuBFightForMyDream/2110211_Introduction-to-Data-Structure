#include <stdexcept>
#include <iostream>
#include "d63_q2b_vector_compress_cp_vector_template.h"
#include "d63_q2b_vector_compress_method.h"

int main() {
    int n;
    CP::vector<int> v;
    std::cin >> n;
    for (int i= 0;i < n;i++) {
        int a;
        std::cin >> a;
        v.push_back(a);
    }
    v.compress();

    v.print_for_quiz();
}
