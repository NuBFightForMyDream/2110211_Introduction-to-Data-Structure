# include <iostream> 
# include <map>
# include <utility> // pair 
# include <algorithm>
# include <vector>
using namespace std ; 

int main() {
    // try using vector & sort 
    int N ; cin >> N ; 
    vector<int> numbers ;
    for (int i = 0 ; i < N ; i++) { 
        int num ; cin >> num ; 
        numbers.push_back(num) ; 
    }

    // sort vector then check 1 to N 
    sort( numbers.begin() , numbers.end() ) ;

    bool isPermutated = true ; 
    for (int pos = 0 ; pos < N ; pos++) { 
        if (numbers[pos] != pos + 1) {
            isPermutated = false ; 
            cout << "NO" << endl ; 
            break ; 
        }
    }

    if (isPermutated == true) {
        cout << "YES" << endl ;  ; 
    }
}
