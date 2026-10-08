# include <iostream>
# include <set> 
# include <algorithm> // find
# include <vector>
using namespace std ;

int main() {
    // using set instead of vector 

    // step 1 : input data 
    int M , N ; cin >> M >> N ; 
    set<int> set_1 ;
    set<int> set_2 ;
    for (int i = 0 ; i < M ; i++) {
        int value ; cin >> value ; 
        set_1.insert(value) ; // set automatically sort 
    }
    for (int j = 0 ; j < N ; j++) {
        int value ; cin >> value ; 
        set_2.insert(value) ; 
    }

    // step 2 : intersect vector
    vector<int> intersected_value ; 
    // loop then check each element : if found , add to intersected else skip
    for (const int &each_number : set_1) { // using const for not editing element
        if ( set_2.find(each_number) != set_2.end() ) { 
            intersected_value.push_back(each_number) ; 
        }
    }
    
    // step 3 : output
    for (int j = 0 ; j < intersected_value.size() ; j++) {
        cout << intersected_value[j] << " " ; 
    }
    
}
