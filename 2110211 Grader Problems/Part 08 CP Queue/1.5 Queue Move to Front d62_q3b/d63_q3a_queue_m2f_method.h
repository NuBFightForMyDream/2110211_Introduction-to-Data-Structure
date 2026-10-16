#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here

    // guard condition : check if it doesn't more than mSize
    if (pos >= mSize) return ;  
    
    // define element to move front 
    T element_to_move_front = mData[ (mFront + pos) % mCap ] ; 

    // move data forward (right) 1 step 
    // but beware of data replaced , so we need to reverse add from last to first 

    /*
    for (size_t i = 0 ; i < pos ; i++) { // start from 0 to before pos
        mData[ (mFront + (i)) % mCap ] = mData[ (mFront + (i-1)) % mCap ] ; // mData[i+1] = mData[i]
        // don't forget that pos start from mFront
    }
    */

    for (size_t i = pos ; i > 0 ; --i) { // start from pos to before 0 
        mData[ (mFront + i) % mCap ] = mData[ (mFront + (i-1)) % mCap ] ; // mData[i] = mData[i-1]
        // now data wont be replaced
    }

    // replace front data with element_to_move
    mData[ (mFront + 0) % mCap ] = element_to_move_front ;                                                                 
}

#endif
