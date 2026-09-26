#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here

    // define reserved_space
    size_t reserved_space_a = this->mCap - this->mSize ; 
    size_t reserved_space_b = other.mCap - other.mSize ; 

    if (reserved_space_a < reserved_space_b) return -1 ; 
    else if (reserved_space_a == reserved_space_b) return 0 ; 
    else return 1 ; 
}

#endif
