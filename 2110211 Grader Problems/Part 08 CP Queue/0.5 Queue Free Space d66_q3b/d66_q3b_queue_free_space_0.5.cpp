#include <iostream>
#include <queue>
using namespace std ; 

int main() { 
    int count_operation ; cin >> count_operation ; 
    // define mSize , mCap 
    size_t mSize = 0 , mCap = 1 ; 

    for (int i = 0 ; i < count_operation ; i++) { 
        int operation , times ; 
        cin >> operation >> times ; 

        if (operation == 0) { // push k times
            size_t new_capacity = mSize + times ; 

            // push will expand mSize but need to ensure capacity
            mSize += times ;

            // ensure capacity 

            /* This doesn't work because we only check 1 time 
            if ( new_capacity > mCap ) { // new_size = mSize + 1
                // check if given is more than 2 times of mCap 
                if ( new_capacity > (2 * mCap) ) { 
                    mCap = new_capacity ; 
                }
                else { 
                    mCap = 2 * mCap ; 
                }
            }
            */

            // maybe check with while loop instead
            // while (mSize > mCap) mCap *= 2 ; -> maybe check in all operations
        }

        else if (operation == 1) { // pop k times
            // pop will decrease mSize
            mSize -= times ; 
        }

        while (mSize > mCap) mCap *= 2 ;

    }

    // after loop , calculate free space (mCap - mSize)
    cout << mCap - mSize << endl ; 
}