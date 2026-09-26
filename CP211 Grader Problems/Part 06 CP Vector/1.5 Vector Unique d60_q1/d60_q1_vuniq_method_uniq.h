#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include <algorithm> // for std::find in set
#include <set>
#include <vector>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here

  std::set<T> found_element_set ; 
  std::vector<T> found_element_vector ; // just use for store data by order

  for (int i = 0 ; i < this->size() ; i++) { 
    // define v[i] 
    T& each_element = (*this)[i] ; 

    // check element in found_element vector first 
    if ( found_element_set.find(each_element) != found_element_set.end() ) { 
      continue ; // dont add if found already
    } 
    else { 
      found_element_set.insert(each_element) ; 
      found_element_vector.push_back(each_element) ; 
    }
  }

  // after finish loop , replace v with found_vector
  for (int i = 0 ; i < found_element_vector.size() ; i++) { 
    // replace mData[i] with found_element_vector
    mData[i] = found_element_vector[i] ; 
  }

  // resize mSize 
  mSize = found_element_vector.size() ; 
}

#endif
