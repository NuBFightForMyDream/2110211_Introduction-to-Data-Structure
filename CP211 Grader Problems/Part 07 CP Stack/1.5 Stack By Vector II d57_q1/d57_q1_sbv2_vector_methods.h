#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "d57_q1_sbv2_cp_stack_template.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const {
  //write your code here
  return v.size() ; 
}

template <typename T>
const T& CP::stack<T>::top() const {
  //write your code here
  return v[ v.size() - 1 ] ; 
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  //write your code here
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  //write your code here
  v.pop_back() ; 
}

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
  //write your code here

  // define temp vector for deep push 
  CP::stack<T> temp_stack ; 

  // push data from CP::stack to std::vector
  for (int i = 0 ; i < depth ; i++) { 
      temp_stack.push( this->top() ) ; 
      this->pop() ; 
  }

  // depp push data
  this->push(element) ; 

  for (int i = 0 ; i < depth ; i++) { 
      auto top_element = temp_stack.top() ; 
      this->push(top_element) ;
      temp_stack.pop() ;  
  }
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  //write your code here
  for (int i = 0 ; i < w.size() ; i++) { 
    auto& element_to_push = w[i] ; 
    this->push( element_to_push ) ; 
  }
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  //write your code here

  while ( (this->empty() == false) ) { 
      if (this->top() != e) this->pop() ; 
      else break ; 
  }
}

#endif

