#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {

    /* 
        // Note : this solution has some TLE from copy then rotate

        // define CP:vector to get data in range 
        CP::vector<T> to_rotate_vector ; 

        // create to_rotate_vector first 
        for (auto it = first ; it != last ; it++) { 
            to_rotate_vector.push_back(*it) ; 
        }

        // CP::vector<T> rotated_vector = to_rotate_vector ; // copy constructor of vector 

        // use formula from rotate : (i - 1 + k) % n + 1
        size_t size_rotate = to_rotate_vector.size() ; 

        for (int i = 0 ; i < size_rotate ; i++) { 
            this->at( first + i - begin() ) = to_rotate_vector[ (i + k) % size_rotate ] ; 
        }
    */

    // k can be more than 1 loop , so we mod k 
    size_t rotate_range = last - first ; 
    if (rotate_range == 0) return ; 
    k = k % rotate_range ; 
    if (k == 0) return ; 

    // logic : keep first k data (to be insert after rotate)

    // keep first k data 
    CP::vector<T> temp_first_k ; 
    for (auto it = first ; it != first + k ; ++it) temp_first_k.push_back(*it) ; 

    // move data left k pos 
    for (size_t j = first-begin() ; j < last-begin() - k ; j++) { // [first + k + 1 , last-1]
        mData[j] = mData[j+k] ; // Ex : mData[0] = mData[5]
    }
    size_t size_other = rotate_range - k ; 

    // replace temp_first_k data
    size_t p = 0 ; 
    for (size_t l = (first-begin()) + size_other ; l < (first-begin()) + size_other + k ; l++) { // [first+size , first+size+k]
        mData[l] = temp_first_k[p] ; 
        p++ ; 
    }

}

#endif
