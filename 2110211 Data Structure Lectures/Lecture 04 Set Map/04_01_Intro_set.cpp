# include <iostream> 
# include <set>
# include <algorithm>
using namespace std ; 

void print_set(set<int> &nums) { 
    for (auto it = nums.begin() ; it != nums.end() ; it++) { 
        cout << *it << " " ; 
    }
}
int main() { 
    // Set normally sort ascending [fast at sorting]
    set<int> numbers = {99,67,3,65,-142,89,69,6771} ; 
    print_set(numbers) ; cout << endl ; 

    numbers.insert(10) ; // insert then sort ascending
    print_set(numbers) ; cout << endl ; 

    numbers.erase(67) ; 
    print_set(numbers) ; cout << endl ; 

}