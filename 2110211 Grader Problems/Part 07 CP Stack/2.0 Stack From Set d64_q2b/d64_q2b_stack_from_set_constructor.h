#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "d64_q2b_stack_from_set_cp_stack_template.h"

//DO NOT INCLUDE ANYTHING

template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  // write your code ONLY here
  // build constructor

  // no need to worry about size , because in push() method already 

  // define mCap mSize mData (all of these are from default constructor)
  int cap = 1 ; 
  mData = new T[cap]() ; // define array of T with size cap (no need to declare type)
  mSize = 0 ; 
  mCap = cap ; 

  // loop with iterator in set 
  // BUT BUT : we store first as "top element" , so we need to push "last" first 

    /* Using Fo loop is having edge case , so using while loop instead 
    for (auto it = last ; it != first ; --it) { // adding first later 
        // we dont need last (we need itr before last) , so just ignore last 
        if ((it != last) && (first != last)) { 
          push(*it) ;  
        }
    }
    push(*first) ; 
    */

  if (first != last) { 
    auto itr = last ; 
    while ((itr != first) ) { 
      --itr ; 
      push(*itr) ; // no need to push first because we already decrease itr
    }
  }

}

#endif
