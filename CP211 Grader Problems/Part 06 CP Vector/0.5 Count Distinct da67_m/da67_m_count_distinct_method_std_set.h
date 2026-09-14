#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "da67_m_count_distinct_cp_vector_template.h"
#include <set> // std::set
// #include "vector.h" : for submission , pls dont forgot to change it back

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    // Write your code here

    // step 1 : define STD Set to store distinct value
    std::set<T> unique_values ; 

    // step 2 : loop from itr_a to before itr_b 
    for (auto it = a ; it != b ; ++it) { // auto = CP::vector<T>::iterator
        // note that a and b is iterator already , so no need to use this->begin())+a anymore

        // just insert , set will auto sort and auto get unique members
        unique_values.insert(*it) ; // add value if not ever seen
    }
    
    // step 3 : return unique_values size
    return unique_values.size() ; // size_t type
}

#endif