#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <utility>
#include <vector>

template <typename T>
void CP::stack<T>::push(T element, int count) {
  // your code here
  ensureCapacity( mSize + count ); 

  // push 
  for (int i = 0 ; i < count ; i++) { 
      this->push(element) ; 
  }
}

template <typename T>
void CP::stack<T>::push(std::vector<std::pair<T, int>> elements) {
  // calculate total count (to ensure capacity)
  int total_capacity = 0 ; 
  for (auto &[element , count] : elements) { 
      total_capacity += count ; 
  }

  // ensure capacity 
  ensureCapacity( mSize + total_capacity ) ;
  
  // push 
  for (auto &[each_element , each_count] : elements) { 
      for (int i = 0 ; i < each_count ; i++) { 
          this->push(each_element) ; 
      }
  }

}

#endif
