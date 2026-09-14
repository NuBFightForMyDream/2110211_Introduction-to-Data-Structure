#include "da67_m_count_distinct_cp_vector_template.h"
#include "da67_m_count_distinct_count_distinct_method.h"
//#include "da67_m_count_distinct_method_with_std_set.h"
#include <iostream>

using std::cin;
using std::cout;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    CP::vector<int> vec;
    std::string cmd;
    while (true)
    {
        cin >> cmd;
        if (cmd == "p") // print vector
        {
            for (auto &x : vec)
            {
                cout << x << " ";
            }
            cout << "\n";
            cout << vec.size() << "\n";
        }
        else if (cmd == "a") // insert value 
        {
            int X, Y;
            cin >> X >> Y;
            vec.insert(vec.begin() + X, Y);
        }
        else if (cmd == "c") // count distinct
        {
            int P, Q;
            cin >> P >> Q;
            cout << vec.count_distinct(vec.begin() + P, vec.begin() + Q) << "\n";
        }
        else if (cmd == "q")
        {
            break;
        }
    }
}