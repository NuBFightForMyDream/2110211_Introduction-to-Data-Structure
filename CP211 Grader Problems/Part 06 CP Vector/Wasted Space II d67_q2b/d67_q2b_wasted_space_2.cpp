#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std ; 

int main() { 
    int count_operation ; 
    cin >> count_operation ; 

    // define CP::vector properties 
    long long mSize = 0 ; // start with no data inside
    long long mCap = 1 ; // start with capacity 1

    for (long long i = 0 ; i < count_operation ; i++) { 
        char operation ; long long value ; 
        cin >> operation >> value ;  

        // check operation 
        if (operation == 'p') { // push_back n times
            // push_back will increase mSize 
            mSize += value ; 

            // check size 
            while (mSize > mCap) { 
                mCap *= 2 ; 
            }
        }

        else if (operation == 'o') { // pop_back n times
            // pop_back will decrease mSize 
            mSize -= value ; 
        } 

        else if (operation == 'r') { // resize mSize with value N

            // check size before resize value
            mCap = max(value , 2*mCap) ;
            
            // resize mSize 
            mSize = value ; 
        }
    }

    // after loop , calculate wasted space (mCap - mData)
    cout << (mCap - mSize) << endl ; 
}