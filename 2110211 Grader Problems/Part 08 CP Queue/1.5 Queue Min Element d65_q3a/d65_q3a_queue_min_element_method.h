#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  T min_element_val ; // only positive number in CP Queue
  bool first_found = false ; 

  // check if position exist in CP queue
  for (int i = 0 ; i < pos.size() ; i++) { 
      size_t current_pos = pos[i] ; 
    
      // case 1 : pos not exist 
      if ( current_pos >= mSize ) { 
          continue ; 
      }

      else {
          // compare data at that pos VS min_element_val
          T element_at_queue_pos = mData[ (mFront + current_pos) % mCap ] ; // use mFront (this->front()) then mod
          // use mCap , dont use mSize

          /* from indexing print
              for (size_t i = 0;i < mSize;i++) {
                std::cout << mData[(mFront+i) % mCap] << " ";
              }
          */

          // define first time value 
          if (first_found == false) { 
              min_element_val = element_at_queue_pos ; 
              first_found = true ; 
          }

          else { 
              if ( comp(element_at_queue_pos , min_element_val) == true ) { 
                  min_element_val = element_at_queue_pos ; 
              }
          }
          
      }
  }

  //should return something
  return min_element_val ;
}

#endif
