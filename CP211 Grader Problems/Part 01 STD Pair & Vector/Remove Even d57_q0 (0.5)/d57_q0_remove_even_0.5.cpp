// Data Quiz 2557 Grader 0 : Remove Even (0.5 Star)
# include <iostream>
# include <vector>
using namespace std;

// create function for remove even index in vector
void remove_even(vector<int> &v , int a , int b) {
    // write your code only in this function

    // Idea : check if index is even , if even then remove from vector
    // a = Starting Pos , b = Ending Pos

    // Note : for loop using remove() will shift index , so use .erase() is safer (and using while loop)
        // from Hint : erase from back to front to prevent index shift
    for (int pos = b ; pos >= a ; pos--) {
        if (pos % 2 == 0) { // check if even pos
            v.erase( v.begin() + pos ) ; // erase at pos of iterator (v.begin() + pos)
        } 
    }   
}

int main() {
    // Step 1 : Read input
    int n,a,b; // n = vector size
    cin >> n;

    // Step 2 : Input vector elements 
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        // append element
        v.push_back(c);
    }

    // Step 3 : Input size
    cin >> a >> b;

    // Step 4 : Call function
    remove_even(v,a,b);

    // Step 5 : Display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}