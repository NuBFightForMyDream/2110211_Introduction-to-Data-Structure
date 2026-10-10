#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  //
  // you need to return something

  // formula : add mSize for 1 loop . -1 then +1 for original index
  if (idx >= 0)

  // this case works only for 
  return mData[ ((idx + mFront) - 1 + mSize) % mSize + 1 ] ; // from front of queue with sequence idx
  
}

#endif
