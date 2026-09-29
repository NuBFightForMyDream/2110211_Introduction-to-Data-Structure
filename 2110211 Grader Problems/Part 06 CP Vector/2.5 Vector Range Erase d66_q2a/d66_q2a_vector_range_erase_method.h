#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "d66_q2a_vector_range_erase_cp_vector_template.h"
#include <algorithm>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here

  // define reversed_order of vector (maybe just sort reverse)
  sort(ranges.rbegin() , ranges.rend()) ; 

  // delete ranges of iterator 
  for (int i = 0 ; i < ranges.size() ; i++) { 
      auto pair_ranges = ranges[i] ; 
      auto left = pair_ranges.first , right = pair_ranges.second ; 

      for (auto it = left ; it != right + 1 ; ++it) { 
        this->erase(it) ;
      }
  }

}

#endif
