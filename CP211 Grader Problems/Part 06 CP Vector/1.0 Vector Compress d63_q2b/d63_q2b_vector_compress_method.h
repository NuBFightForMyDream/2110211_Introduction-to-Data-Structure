#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here

    // Key of this problem : decrease mCap to mSize of CP::vector
    // Ex : mSize = 10 , mCap = 67 --> mSize = 10 , mCap should be decrease to 10 duay

    // steps of doing compressed vector : 
        // 1. create new mData array (no need to create CP::vector)
        // 2. copy data to new CP::vector
        // 3. delete old CP::vector
        // 4. [can't use copy constructor & copy assignment operator] -> change pointer to new array then resize mCap

    // step 1 
    // CP::vector<T> decreased_size_cp_vector(this->size()) ; // custom constructor with size 
    T* decreased_size_array = new T[ this->size() ]() ; // pointer to array of type T , size = mSize 

    // step 2
    for (size_t i = 0 ; i < this->size() ; i++) { // loop with old data range
        // add each data into new CP::vector
        // now we can use index [] from operator[] 
        decreased_size_array[i] = (*this)[i] ; // *this refer to mData 
    }

    // step 3 
    delete [] mData ; 

    // step 4 
    mData = decreased_size_array ; // change pointer to new CP::vector
    mCap = mSize ; // resize mCap to mSize


    // note that we use same CP::vector , not creating new so we can use attributes 
    // and we can't create new CP::vector from reason of copying data (which will use copy assignment operator)

    // cheat line : see code from expand() function [it's the same thing i've written] --> expand(mSize) ; // expand with mSize

    /*
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for (size_t i = 0;i < mSize;i++) {
                    arr[i] = mData[i];
                }
                delete [] mData;
                mData = arr;
                mCap = capacity;
            }
    */

}

#endif
