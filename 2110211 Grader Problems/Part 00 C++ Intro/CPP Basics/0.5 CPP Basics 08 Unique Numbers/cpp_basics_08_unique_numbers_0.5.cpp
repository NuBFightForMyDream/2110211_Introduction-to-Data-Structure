#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std ; 

int main() { 
    set<int> numbers_list ; 
    int summation = 0 ; 

    int num_count ; cin >> num_count ; 
    for (int i = 0 ; i < num_count ; i++) { 
        int num ; cin >> num ;

        summation += num ; 
        numbers_list.insert(num) ; 
    }

    // output 
    cout << numbers_list.size() << endl ; 
    cout << summation << endl ; 
    for (auto &e : numbers_list) cout << e << " " ;
}
