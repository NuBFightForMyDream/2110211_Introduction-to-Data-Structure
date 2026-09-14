#include <iostream>
#include <vector>
using namespace std;

int main() { 
    int current_size ; cin >> current_size ; 
    // define default value
    int mSize = current_size ;
    
    // multiply mCap each time by 2 
    int mCap = 1 ; 
    while (mCap < mSize) mCap *= 2 ; 

    // now mCap should be more than mSize 
    int wasted_space = mCap - mSize ; 
    cout << wasted_space << endl ; 

}