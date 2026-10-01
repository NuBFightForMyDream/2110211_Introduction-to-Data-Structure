#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm> // for sorting
#include <utility>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here

    /* Note : Insert each loop isn't bad but will TLE in some case (70 / 100) , so we need to find better solution

    // step 1 : sort sort_vector first 
    // i'll sort reverse (to get most value of index) -> bcz we don't have duplicated index
    std::sort(data.begin() , data.end() , std::greater<std::pair<int,T>>()) ; 

    // insert reverse 
    for (auto &[pos_to_insert , element_to_insert] : data) { 
        this->insert(this->begin() + pos_to_insert , element_to_insert) ; 
    }

  */

  




}

#endif
