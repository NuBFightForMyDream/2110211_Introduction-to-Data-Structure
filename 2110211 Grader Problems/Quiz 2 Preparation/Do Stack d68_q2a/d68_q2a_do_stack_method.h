#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"

// aux_stack_1 is used for "undo"
// aux_stack_2 is used for "redo"

template<typename T>
void CP::stack<T>::push(const T &value) {
  //You can write your code below here
  
} 

template <typename T>
void CP::stack<T>::pop() {
  //Do not modify this line
  if (size() == 0) throw std::out_of_range("index of out range") ;
  //You can write your code below here

  return ;
}

template <typename T>
void CP::stack<T>::undo() {
  //You can write your code below here
  return ;
};

template <typename T>
void CP::stack<T>::redo() {
  //You can write your code below here
  return ;
}

#endif