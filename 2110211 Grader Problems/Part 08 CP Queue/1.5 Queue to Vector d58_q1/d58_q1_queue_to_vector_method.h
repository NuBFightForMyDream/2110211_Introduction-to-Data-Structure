#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>

// constructor
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  
  // return vector<T> which consists of first K member of queue from mFront

  // guard case : check K 
  if (k > mSize) k = mSize ; 

  // now copy data from CP Queue to std vector
  for (int i = 0 ; i < k ; i++) { 
      T element_to_add = mData[ (mFront + i) % mCap ] ; 
      res.push_back( element_to_add ) ; 
  }

  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here 
  
  // define mCap and mSize and mFront
  size_t dist = to - from ; 
  mSize = dist ; 
  mCap = mSize ; // mCap = mSize = dist
  mFront = 0 ; // start from 0 

  // define new array the delete old memory 
  T* arr = new T[mSize]() ; // with size mSize
  // delete [] mData ; --> mData nt created , so no need to delete old memory
  
  auto it = from ; // this is iterator which will run from "from" to "to"

  for (size_t i = 0 ; i < dist ; i++) { // copy data 
      arr[i] = *it ; 
      it++ ; 
  }

  // replace mData with arr 
  mData = arr ; // mData point to arr 

}

#endif
