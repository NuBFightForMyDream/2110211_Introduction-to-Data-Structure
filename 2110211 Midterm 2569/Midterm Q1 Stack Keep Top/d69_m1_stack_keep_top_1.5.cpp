/*
(10 คะแนน) จงแก้ไขคลาส CP::stack โดยให้เพิ่มฟังก์ชัน keep_top(size_t k) ซึ่งจะเก็บไว้เฉพาะข้อมูล k ตัวบนสุดของ stack (หาก
k > mSize หมายความว่าให้เก็บข้อมูลไว้ทุกตัว) โดยฟังก์ชันนี้จะต้องทำให้ mData มีขนาดเท่ากับจำนวนที่เหลือพอดี (ในกรณีที่ k =
0 ให้ mData มีขนาด 1 ช่องพอดี) ให้ระวังกรณีที่ memory leak ด้วย
*/

#include <iostream>
#include <stack>
#include <algorithm>

#include "d69_m_q1_stack_keep_top_cp_stack_template.h"

template <typename T>
void CP::stack<T>::keep_top(size_t k) { 
    // check condition 
    if (k == 0) {  // from problem , it means having mCap (not mSize) as 1
        
        // reserve new mData
        T* newData = new T[1]; // array 

        // free old memory out
        delete[] mData ; 
        mData = newData; // point to newData

        // define mSize and mCap 
        mSize = 0 ; 
        mCap = 1 ; 
    }
    
    else if (k <= mSize) { // opposite condition
        // create temp stack (for keeping top k)
        std::stack<T> temp_top_k ; 

        // loop keep top
        for (size_t i = 0 ; i < k ; i++) { 
            temp_top_k.push( this->top() ) ; 
            this->pop() ; // pop out
        }

        // for the others , get the fk out of here 
        while (this->empty() == false) { 
            this->pop() ; 
        }

        // put data back
        while (temp_top_k.empty() == false) { 
            this->push( temp_top_k.top() ) ;
            temp_top_k.pop() ;  
        } 

        // memory leak management
            // reserve new memory 
            T* newData = new T[k] ; // size k -> mCap = k
            
            // copy data 
            for (size_t i = 0 ; i < k ; i++) { 
                newData[i] = mData[i] ; 
            }

            // free old data & point to newData
            delete[] mData ; 
            mData = newData ;
            
            // resize mCap & mSize 
            mSize = k ; // should be size k 
            mCap = k ; // should be size k

    }

    else if (k > mSize) { 
        // memory leak management
        
        size_t new_cap = 0 ; 
        if (mSize != 0) new_cap = mSize ; 
        else new_cap = 1 ; 

        // reserve new memory 
        T* newData = new T[new_cap] ;  

        // copy all data 
        for (size_t i = 0 ; i < mSize ; i++) { 
            newData[i] = mData[i] ; 
        }

        delete[] mData ; // free old memory 
        mData = newData ; // point to newData
        mCap = new_cap ; 
        // mSize still same
    }
}

int main() {
    size_t cases[] = {0, 1, 3, 5, 8};

    for (size_t k : cases) {
        CP::stack<int> s;
        for (int i = 1; i <= 5; ++i) {
            s.push(i);
        }

        s.keep_top(k);

        std::cout << "k=" << k
                  << " size=" << s.size()
                  << " top->bottom:";

        while (!s.empty()) {
            std::cout << ' ' << s.top();
            s.pop();
        }
        std::cout << '\n';
    }

    // Empty stack
    CP::stack<int> empty;
    empty.keep_top(3);
    std::cout << "empty size=" << empty.size() << '\n';

    // Reuse after keeping zero elements
    CP::stack<int> reuse;
    reuse.push(10);
    reuse.keep_top(0);
    reuse.push(99);

    std::cout << "reuse size=" << reuse.size()
              << " top=" << reuse.top() << '\n';
}

/* Expected Result
k=0 size=0 top->bottom:
k=1 size=1 top->bottom: 5
k=3 size=3 top->bottom: 5 4 3
k=5 size=5 top->bottom: 5 4 3 2 1
k=8 size=5 top->bottom: 5 4 3 2 1
empty size=0
reuse size=1 top=99
*/