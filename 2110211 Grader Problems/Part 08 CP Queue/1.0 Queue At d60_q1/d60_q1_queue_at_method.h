#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  //
  // you need to return something

  /*
    const T& front() const {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[mFront];
    }
    const T& back() const {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[(mFront + mSize - 1) % mCap];
    }
  */

  // logic similar as front and back 
  if (idx >= 0) { // get front 
      return mData[ (mFront + idx) % mCap ] ; // mod with capacity
  }
  else { 
      return mData[ (mFront + idx + mSize) % mCap ] ; // mod with capacity but need to add with mSize first for positive value
  }
}

#endif
