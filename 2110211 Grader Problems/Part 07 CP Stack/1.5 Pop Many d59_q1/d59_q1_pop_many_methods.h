#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here

  // check CP::Stack size first
  size_t size_to_delete = std::min(K , this->mSize) ; 

  for (int i = 0 ; i < size_to_delete ; i++) { 
    this->pop() ; 
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //
  //don't forget to return an std::stack

  // check CP::Stack size first
  size_t size_to_delete = std::min(K , this->mSize) ; 

  std::stack<T> temp_stack , reverse_temp_stack ; // reverse for order that problems want

  for (int i = 0 ; i < size_to_delete ; i++) { 
    auto top_element = this->top() ; 
    temp_stack.push( top_element ) ; 
    this->pop() ; 
  }

  // reverse stack for order
  while ( temp_stack.empty() == false ) { 
      reverse_temp_stack.push( temp_stack.top() ) ; 
      temp_stack.pop() ; 
  }

  return reverse_temp_stack ; 

}

#endif
