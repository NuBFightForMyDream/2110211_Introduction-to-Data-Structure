# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
void reverse(vector<int> &v , vector<int>::iterator a , vector<int>::iterator b) {
    // write your code only in this function    
        // iterator a : point at (v.begin() + a) -> a 
        // iterator b : point at (v.begin() + b + 1) -> next to b 

    // Logic : reverse side element until found middle
    b-- ; // move to b (instead of next to b)
    while (a < b) {
        swap( *a , *b ) ; // swap at rightmost until found middle 
        // or using iter_swap(a,b) 
        a++ ; // scope right down
        b-- ; // scope left down
    }
        
}
int main() {
    // read input
    int n,a,b;
    cin >> n;
 
    // create vector 
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        v.push_back(c); // append value 
    }

    // input size of vector
    cin >> a >> b;
 
    // call function
    reverse( v , v.begin()+a , v.begin()+b+1 );
    
    // display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}