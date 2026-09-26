#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "d66_q2b_stack_reverse_cp_stack_template.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	// write your code here

	// define stack 
	CP::stack<T> original_data_stack ; // maybe use std::vector is better solution

	// Logic : push to stor -> stor reverse -> reverse (to original order) -> push_back to reverse order 
	// (normally reverse do 1 time but cant , so we need to do 3 times)
	CP::stack<T> to_reverse_stack ; 
	CP::stack<T> to_reverse_back_stack ; 

	// check condition first and last
	if (this->empty()) return ;  
	if (first > last) return ; 
	if (first > this->size()-1) return ; 
	else { 
		// cap first and last in case < 0 or > size
		size_t capped_first = first ; 
		size_t capped_last = std::min(last , this->size()-1) ; 

		// deep push until first --> store in original_data_stack 
		for (size_t i = 0 ; i < capped_first ; i++) { 
			original_data_stack.push( this->top() ) ; 
			this->pop() ; 
		}

		// first to last --> store in to_reverse_stack 
		for (size_t i = capped_first ; i <= capped_last ; i++) { // including last 
			to_reverse_stack.push( this->top() ) ; 
			this->pop() ; 
		}

		// reverse order --> store in to_reverse_back_stack 
		while (to_reverse_stack.empty() == false) { 
			to_reverse_back_stack.push( to_reverse_stack.top() ) ; 
			to_reverse_stack.pop() ; 
		}

		// push reversed data back into CP::stack 
		while (to_reverse_back_stack.empty() == false) { 
			this->push( to_reverse_back_stack.top() ) ; 
			to_reverse_back_stack.pop() ; 
		}

		// put original data stack back 
		while (original_data_stack.empty() == false) { 
			this->push( original_data_stack.top() ) ; 
			original_data_stack.pop() ; 
		}

	}
	
}

#endif
