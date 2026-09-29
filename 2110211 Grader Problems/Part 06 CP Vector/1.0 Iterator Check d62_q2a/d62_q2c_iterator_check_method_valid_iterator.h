#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  //write your code here
  // can't use begin() and end()

  // use mSize to check if itr in range 
  if (it >= mData && it < mData + mSize) { // mData = pointer to data , so we can compare with it
    // mData (pointer at begin of data) + mSize (soze of vector = int) = pointer at end 
    return true ; 
  }
  else return false ; 
}

#endif
