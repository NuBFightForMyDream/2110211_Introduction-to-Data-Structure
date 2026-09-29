#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "d67_q2a_vector_multi_unique_cp_vector_template.h"
#include <vector>
#include <map>
#include <algorithm>
#include <functional> // std::greater

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  // itrs = vector of iterator 

  // itrs will be in this form [v.begin() + 1 , v.begin() + 3 , ...]
  // we need to see from iterator that we've seen this data
  
  // NOT FULL from not sorting itrs
  sort(itrs.begin() , itrs.end()) ; 

  std::map<int , int> seen ; // <data_val , index>
  std::vector< int > to_delete_index ; // <index_of_itr_to_delete>

  for (auto each_itr : itrs) { // note that each_itr = CP::vector<T>::iterator
      auto current_index = each_itr - this->begin() ; 

      auto each_value = this->at( current_index ) ; // at index 

      if (seen.count(each_value) == 0) { // never found
           // add info to map 
           seen[each_value] = current_index ; 
      }
      else { // found , add to to_delete
          to_delete_index.push_back( current_index ) ; 
      }
  }
  
  // sort vector descending 
  sort( to_delete_index.begin() , to_delete_index.end() , std::greater<int>() ) ; 

  // delete each iterator 
  for (size_t i = 0 ; i < to_delete_index.size() ; i++) { 
    this->erase( this->begin() + to_delete_index[i] ) ; // erase iterator 
  }


}

#endif
