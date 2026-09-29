#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "d57_q1_sbv1_cp_stack_template.h"
#include <iostream>

// call std::vector commands

template <typename T>
size_t CP::stack<T>::size() const {
  //write your code here
  return v.size() ; 
}

template <typename T>
const T& CP::stack<T>::top() const {
  //write your code here
  return v[v.size() - 1] ; // last element of vector is top of stack
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  //write your code here
  v.push_back(element) ; 
}

template <typename T>
void CP::stack<T>::pop() {
  //write your code here
  v.pop_back() ; 
}

#endif
