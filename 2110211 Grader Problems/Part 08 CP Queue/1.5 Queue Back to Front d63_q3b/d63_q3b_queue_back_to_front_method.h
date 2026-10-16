#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::back_to_front() {
  //write your code here

  // guard condition : if mSize = 0 -> do nothing
  if (mSize == 1) return ; 

    /*
        // to get this task full , should use O(1) (maybe push is a good way)
        T back_element = this->back() ; 

        // push with loop mSize - 1 (leave last element) to temp_queue
        CP::queue<T> temp_queue ; 

        for (size_t i = mFront ; i < (mFront + mSize - 1) % mCap ; i++) { 
            temp_queue.push( this->front() ) ; 
            this->pop() ; 
        }

        // push temp back to queue
        // this->push(back_element) ;  

        while (temp_queue.empty() == false) {
            this->push( temp_queue.front() ) ; 
            temp_queue.pop() ;
        }
    */

    // note that it may not work in O(1) to push to temp_stack 
    // maybe try using mSize , mFront efficiently

    // define back() element 
    T last_element = this->back() ; 

    // logic : old back = new front & mFront
    // old back = mData[mFront + (mSize - 1) % mCap]
    size_t new_mFront = (mFront + (mCap - 1)) % mCap ; // last element = mCap - 1
    
    // define data at front 
    mData[new_mFront] = last_element ; 

    // change mFront
    mFront = new_mFront ; 

}

#endif
