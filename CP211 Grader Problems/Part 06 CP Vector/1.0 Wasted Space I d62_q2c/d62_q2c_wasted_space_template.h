#ifndef D62_Q2C_WASTED_SPACE_TEMPLATE_H
#define D62_Q2C_WASTED_SPACE_TEMPLATE_H

namespace CP {
    template <typename T> 
    class vector { 
        protected : // need to be access via method
            T* mData ; // pointer to mData 
            size_t mCap ; // reserved capacity of data
            size_t mSize ; // current size of data 

            // 3 methods of memory management 
                // void rangeCheck() { } -> no need to write
            
            void expand(size_t capacity) { // must write -> based on ensureCapacity() method
                // create new array for expansion
                T *arr = new T[capacity]() ; // pointer to new array 
                // copy data to new array
                for (size_t i = 0 ; i < mSize ; i++) { 
                    arr[i] = mData[i] ; 
                }
                // delete old array 
                delete [] mData ;
                // change pointer to new array 
                mData = arr ; 
                mCap = capacity ; 
            } 
            void ensureCapacity(size_t capacity) { // not like general cp_vector_template , just for this task only 
                // check size 
                if (capacity > mCap) { 
                    size_t new_size = 0 ;
                    // check again if cap > 2mCap
                    if (capacity > 2 * mCap) new_size = capacity ;
                    else new_size = 2 * mCap ; // double it so no need to worry about +1 space each time
                    
                    // use expand() function 
                    expand(new_size) ; 
                }
            }

        public : 
            // constructor 
                // just only default & custom constructor (others are skipped for this task , no need to use)
            vector() { 
                int cap = 1 ; 
                mData = new T[cap]() ; 
                mCap = cap ; 
                mSize = size ; 
            }   
            vector(size_t cap) { 
                mData = new T[cap]() ; 
                mCap = cap ; 
                mSize = cap ; 
            }  

            // capacity functions (others are no need to write)
            size_t capacity() { 
                return mCap ; 
            }

            // iterator & access & modifier methods
                // write only operator[] method (others are skipped for this task , no need to use)
            T& operator[](int index){ // reference to T  directly
                return mData[index] ; 
            }


    }
}
