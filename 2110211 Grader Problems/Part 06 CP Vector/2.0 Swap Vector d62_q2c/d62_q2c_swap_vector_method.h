#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other) {
    T* temp_mData = this->mData;
    size_t temp_mSize = this->mSize;
    size_t temp_mCap = this->mCap;

    this->mData = other.mData;
    this->mSize = other.mSize;
    this->mCap = other.mCap;

    other.mData = temp_mData;
    other.mSize = temp_mSize;
    other.mCap = temp_mCap;

    // or using std::swap (without using temp data)
}

#endif
