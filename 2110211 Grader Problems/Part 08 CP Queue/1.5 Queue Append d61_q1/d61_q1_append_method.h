#include "d61_q1_append_cp_queue_template.h"
#include "d61_q1_append_cp_stack_template.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        // assign temp stack 
        CP::stack<T> temp_stack ; 

        // s2 below , s1 on top 
        // so reverse logic : push s1 then s2 -> then reverse 

        // ex : s1 = b[1,2,3,4,5]t , s2 = b[11,12]t --> out = b[11,12,1,2,3,4,5]t
        // push s1 -> b[5,4,3,2,1]t then push s2 -> b[5,4,3,2,1,12,11]t
        // then reverse element 

        // push s1 (this) into temp_stack
        while (this->empty() == false) { 
            temp_stack.push( this->top() ) ; 
            this->pop() ; 
        }

        // push s2 to temp_stack
        while (s.empty() == false) { 
            temp_stack.push( s.top() ) ; 
            s.pop() ; 
        }

        // reverse order then push back to s1
        while (temp_stack.empty() == false) { 
            this->push( temp_stack.top() ) ; 
            temp_stack.pop() ; 
        }

    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        // append queue to stack 

        // from example 
        // s1 = b[1,2,3,4,5]t , q1 = f[6,7,8,9]b
        // s1 should be [9,8,7,6,1,2,3,4,5]
        
        // try reverse order -> t[5,4,3,2,1,6,7,8,9]b
        // create temp_stack as reverse order

        // logic : push s1 to temp , then q1 to temp 

        CP::stack<T> temp_stack ; 

        // push s1 to temp_stack 
        while (this->empty() == false) { 
            temp_stack.push( this->top() ) ; 
            this->pop() ; 
        }

        // push q1 to temp_stack 
        while (q.empty() == false) { 
            temp_stack.push( q.front() ) ; 
            q.pop() ; 
        }

        // reverse temp_tack back to s1
        while (temp_stack.empty() == false) { 
            this->push( temp_stack.top() ) ;
            temp_stack.pop() ;  
        }

    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        // append stack to queue

        // push top of stack to back of queue directly
        while (s.empty() == false) { 
            this->push( s.top() ) ; 
            s.pop() ; 
        }

    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        // append queue to queue        
        
        // q1 before q2
        // push q2 to q1 directly then pop q2
        while (q.empty() == false) { 
            this->push( q.front() ) ; 
            q.pop() ; 
        }
    }
}
