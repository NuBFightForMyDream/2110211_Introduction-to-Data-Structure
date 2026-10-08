#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"
#include <queue>
#include <vector>
//You may include here

// logic is like priority_queue

template<typename T>
void CP::stack<T>::push(const T &value) {
  //You can write your code below here
  std::priority_queue<T> temp_pq ; // this will store from more to less

  // before push , ensure capacity first 
  ensureCapacity(mSize + 1) ;

  // loop all data to store in pq
  for (size_t i = 0 ; i < mSize ; i++) { 
    temp_pq.push(mData[i]) ; 
  }
  temp_pq.push(value) ; // push new data 

  // now priority_queue is sorted already 
  // next will pop each data back to mData (from more to less)
  size_t i = 0 ; 
  while (temp_pq.empty() == false) { 
    mData[i++] = temp_pq.top() ; 
    temp_pq.pop() ; 
  }

  mSize++ ; 

}

template <typename T>
void CP::stack<T>::pop() {
  //Do not modify this line
  if (size() == 0) throw std::out_of_range("index of out range") ;

  //You can write your code below here
  mSize-- ; 
}

#endif
