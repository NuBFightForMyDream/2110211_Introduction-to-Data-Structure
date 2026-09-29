#ifndef __STUDENT_H_
#define __STUDENT_H_



template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
       
  /* Insert 1 element : insert(iterator it,const T& element)
    size_t pos = it - begin(); // pos = position to insert 
    ensureCapacity(mSize + 1); // check capacity 
    for(size_t i = mSize;i > pos;i--) {
      mData[i] = mData[i-1]; // move element (start from mSize to before pos)
    }
    mData[pos] = element; 
    mSize++;
    return begin()+pos;
  */

  // note : we need to move element back for insert 

  // step 0 : define position (index) of starting insert
  size_t pos_index = position - begin() ; 

  // step 1 : define distance of inserting 
  size_t dist = last - first ; // ex : last = beg+3 , first = beg+0 -> we get 3 elements (0,1,2)

  // step 2 : ensureCapacity 
  ensureCapacity(mSize + dist) ; 

  // step 3 : move element from position back (do reverse)
  for (size_t i = mSize ; i > pos_index ; i--) {
    // note : last element = mSize - 1
    // move from (mSize - 1) -> + dist -> (mSize-1 + dist)
    mData[i - 1 + dist] = mData[i - 1] ; 
  }

  // step 4 : for loop add inserted range 
  for (int j = 0 ; j < dist ; j++) { 
    // start onsert at pos+j
    mData[pos_index + j] = *(first + j) ; // cuz we start from first to first+n (before last)
    mSize++ ; 
  }

  // return begin() + pos_index + dist ; // return next index we already insert 


}

#endif
