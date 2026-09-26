#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  // create temp stack (to get element inside)
  CP::stack<T> temp_stack ; 

  for (int i = 0 ; i < pos ; i++) { // pop out "pos" times
    temp_stack.push( this->top() ) ; 
    this->pop() ; 
  }

  // push data with value
  this->push( value ) ; 

  // put temp_stack back into (dont worry abt order , it'll be same order)
  while (temp_stack.empty() == false) { 
    this->push( temp_stack.top() ) ; 
    temp_stack.pop() ; 
  }

}

#endif
