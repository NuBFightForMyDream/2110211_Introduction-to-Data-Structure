// DS00_reverse1 : Reverse Vector I (0.5 Star)
# include <iostream>
# include <vector> 
using namespace std ; 

void reverse(vector<int> &v,int a,int b) {
    // write your code only in this function
    // This function reverse element in range a to b (index a to b)
    // Caution : can't use std::reverse

    int pair_swap = (b - a + 1) / 2 ; // distance / 2 = nb.of pair to swap
    int pos_start = a , pos_end = b ; 

    // start swap head and tail then get inside
    for (int round = 0 ; round < pair_swap ; round++) {
        swap( v[pos_start] , v[pos_end] ) ; // swap
        pos_start += 1 ; pos_end -= 1 ; // increase & decrease
    }

    // -- another solution : using 2 iterator -- 
    /*
    while (pos_start < pos_end) { 
        swap( v[pos_start] , v[pos_end] ) ; 
        pos_start++ ; 
        pos_end-- ; 
    }
    */

}
int main() {
    // Step 1 : read input
    int n,a,b; // n = data info , a = start , b = end
    cin >> n;
    vector<int> v; // vector of integer
    for (int i = 0;i < n;i++) {
        // input value
        int c; cin >> c;
        // append value
        v.push_back(c);
    }

    // Step 2 : Enter Range
    cin >> a >> b;

    // Step 3 : call function
    reverse(v,a,b);

    //display content of the vector
    for (auto &x : v) {// for each element (as x) in vector v
        cout << x << " ";
    }
    cout << endl;
}