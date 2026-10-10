#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include <utility>
#include "vector.h"

template <typename T>
std::pair<bool, typename CP::vector<T>::iterator> CP::vector<T>::find(const CP::vector<T>& v2, iterator it) {
  // write your code here
  auto it_found = begin() ; 

  // guard condition
  if ( (v2.size() <= 0) || (it == end()) ) return {false , end()} ;  

      // loop start from it to end
      size_t start_pos = it - begin() ; 
      while (start_pos < end() - begin()) { 
          
          // set checker to true every time to check if all element still in pattern
          bool match_all_sequence = true ; 

          // loop check each element in v2
          for (size_t i = 0 ; i < v2.size() ; i++) { 
              // condition : if not same , set match as false , start_pos++ , then break (to get new start_pos)  
              if (v2[i] != mData[start_pos + i]) { 
                  match_all_sequence = false ; 
                  break ; // if not match , move iterator to check until end
              }
          }

          // check if still match after all check 
          if (match_all_sequence == true) { 
              it_found = begin() + start_pos ; 
              return {true , it_found} ; 
          }

          // add loop 
          start_pos++ ;  

      } 

      // if not return true before this line , should be false 
      return {false , end()} ; 

}
  

#endif
