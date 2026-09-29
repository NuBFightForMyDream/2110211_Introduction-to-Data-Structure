#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include <vector>
#include <utility> // pair 
#include <algorithm>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos , CompareT comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B

  // i'll store with std::vector< std::pair< value , pos > > 
  // shouldn't use map bcz key (data_value) can be duplicated 

  std::vector< std::pair<T , size_t> > value_and_original_pos ; 
  std::vector< size_t > destinations ; // this will use for ascending order 

  // store value in map<pair<T,T>>
  for (auto &each_pos_itr : pos) { 
      auto val = *(each_pos_itr) ; // value at that pos
      value_and_original_pos.push_back( std::make_pair(val , each_pos_itr - mData) ) ;  
      destinations.push_back( each_pos_itr - mData ) ; 
  }
  
  // sort value first , we need to replace data by order of value 
  std::sort(value_and_original_pos.begin(),
          value_and_original_pos.end(),
          [&comp](const auto &a, const auto &b) {
              return comp(a.first, b.first);
          });

  // sort destinations
  std::sort(destinations.begin() , destinations.end()) ; 

  // replace data in mData
  for (size_t i = 0 ; i < destinations.size() ; i++) { 
    auto &value_to_replace = value_and_original_pos[i].first ; 
    mData[ destinations[i] ] = value_to_replace ; 
  }


}

#endif
