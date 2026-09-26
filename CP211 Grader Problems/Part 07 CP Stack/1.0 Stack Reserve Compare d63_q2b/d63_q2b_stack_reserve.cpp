#include <iostream>
#include "d63_q2b_stack_reserve_cp_stack_template.h"
#include "d63_q2b_stack_reserve_method_compare_reserve.h"

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);

    int n,m;
    CP::stack<int> a,b;
    std::cin >> n >> m;
    for (int i = 0;i < n;i++) {
        int x;
        std::cin >> x;
        a.push(x);
    }
    for (int i = 0;i < m;i++) {
        int x;
        std::cin >> x;
        b.push(x);
    }
    std::cout << "a.compare_reserve(b) = " << a.compare_reserve(b) << std::endl;
    std::cout << "b.compare_reserve(a) = " << b.compare_reserve(a) << std::endl;
}
