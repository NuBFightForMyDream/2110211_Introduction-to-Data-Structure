#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "da67_m_count_distinct_cp_vector_template.h"
// #include "vector.h" : for submission , pls dont forgot to change it back

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    // Write your code here

    // step 1 : define CP Vector to store distinct value
    CP::vector<T> unique_values ; // now have mData , mSize = 0 , mCap = 1 (Default Constructor)

    // step 2 : loop from itr_a to before itr_b 
    for (auto it = a ; it != b ; ++it) { // auto = CP::vector<T>::iterator
        // note that a and b is iterator already , so no need to use this->begin())+a anymore
        // this = CP::Vector<T>
        // use contains() method to check if elements are in vector
        if (unique_values.contains(*it) == false) unique_values.push_back(*it) ; // add value if not ever seen
    }
    
    // step 3 : return unique_values size
    return unique_values.size() ; // size_t type
}

#endif