#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "d67_q2a_do_stack_cp_stack_template.h"

// note : stack_b has purpose to keep reverse of stack a 
template <typename T>
void CP::stack<T>::pop() {
	// modify method here

	// if stack_a is empty , pop_bottom from stack_b (which was top element from stack_a)
	if (stack_a.empty() == true) {
		while (stack_b.empty() == false) { 
			T top_element = stack_b.top() ; 
			stack_a.push( top_element ) ; 
			stack_b.pop() ; 
		}
	}
	else if (stack_b.empty() == false) {
		// can directly pop a out 
		stack_a.pop() ; 
	}
}

template <typename T>
const T& CP::stack<T>::top() {
	// modify method here
	if (stack_a.empty() == false) return stack_a.top();
	else if (stack_b.empty() == false) return stack_b.pop() : 
}

template <typename T>
const T& CP::stack<T>::bottom() {
	// write your code here

	// change all data from stack_a to stack_b 
	// then return top of stack_b (which is stack_a bottom)
	while (this->stack_a.empty() == false) { 
		this->stack_b.push( this->stack_a.top() ) ; 
		this->stack_a.pop() ; 
	}

	return this->stack_b.top() ; 
	
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	// write your code here

}

template <typename T>
void CP::stack<T>::pop_bottom() {
	// write your code here

	// change all data from stack_a to stack_b 
	while (this->stack_a.empty() == false) { 
		this->stack_b.push( stack_a.top() ) ; 
		this->stack_a.pop() ; 
	}

	// then pop top element in stack_b
	this->stack_b.pop() ; 

	// then return all element back to stack_a 
	while (this->stack_b.empty() == false) { 
		this->stack_a.push( stack_b.top() ) ; 
		this->stack_b.pop() ; 
	}
}
#endif