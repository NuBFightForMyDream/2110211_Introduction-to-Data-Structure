#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  
  // define pos to move back
  T element_to_move_back = mData[ (mFront + pos) % mCap ] ; 

  // loop from pos to mSize-2 (second last element) <-- move backward (left) 1 step 
  for (size_t i = pos ; i < mSize - 1 ; i++) { 
      // note that we always start with mFront , but dont forget to mod mCap
      mData[(mFront + i) % mCap] = mData[(mFront + (i+1)) % mCap] ; 
  }

  // replace last element with element_to_move_back
  mData[(mFront + (mSize - 1)) % mCap] = element_to_move_back ; // last element = mSize-1 from mFront

}

#endif
