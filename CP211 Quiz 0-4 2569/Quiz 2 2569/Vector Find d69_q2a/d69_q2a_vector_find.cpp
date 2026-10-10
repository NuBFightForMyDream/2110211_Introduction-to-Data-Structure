#include <iostream>
#include <vector>
#include <string>

#include "d69_q2a_vector_find_cp_vector_template.h"
#include "d69_q2a_vector_find_method.h"

static const char nl = '\n';
static const std::string LINE_BREAK = "-------------------------";

void test(int mode) {
    size_t n;
    std::cin >> n;
    CP::vector<int> vec;
    std::vector<int> prev(n);
    for (size_t i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        vec.push_back(x);
        prev[i] = x;
    }
    bool modified = false;
    size_t q;
    std::cin >> q;
    while (q--) {
        size_t p, m;
        std::cin >> p >> m;              // p = ตำแหน่งเริ่ม (0 <= p <= n)
        CP::vector<int> v2;
        std::vector<int> prev2(m);
        for (size_t i = 0; i < m; i++) {
            int x;
            std::cin >> x;
            v2.push_back(x);
            prev2[i] = x;
        }
        std::pair<bool, CP::vector<int>::iterator> res = vec.find(v2, vec.begin() + p);
        if (mode == 1) {
            std::cout << res.first << nl;
        }
        else {
            long long pos;
            if (!res.first && res.second == vec.end()) {
                pos = -1;
            }
            else {
                pos = res.second - vec.begin();
            }
            std::cout << res.first << ' ' << pos << nl;
        }
        if (v2.size() != m) {
            modified = true;
        }
        else {
            for (size_t i = 0; i < m; i++) {
                if (v2[i] != prev2[i]) {
                    modified = true;
                    break;
                }
            }
        }
    }
    if (vec.size() != n) {
        modified = true;
    }
    else {
        for (size_t i = 0; i < n; i++) {
            if (vec[i] != prev[i]) {
                modified = true;
                break;
            }
        }
    }
    if (modified) {
        std::cout << "MODIFIED" << nl;
    }
    std::cout << LINE_BREAK << nl;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        int mode;
        std::cin >> mode;
        test(mode);
    }

}
