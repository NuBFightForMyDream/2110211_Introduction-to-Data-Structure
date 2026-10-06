#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

// note : stack_b has purpose to keep reverse of stack a 
template <typename T>
void CP::stack<T>::pop() {
	// modify method here

	// if stack_a is empty , pop_bottom from stack_b (which was top element from stack_a)
	if ((stack_a.empty() == true) && (stack_b.empty() == false)) {
		while (stack_b.empty() == false) {  
			stack_a.push( stack_b.top() ) ; 
			stack_b.pop() ; 
		}
		// pop out stack_a 
		stack_a.pop() ; 
	}
	else if ((stack_a.empty() == false)) { // in case a & b still have data 
		// can directly pop a out 
		stack_a.pop() ; 
	}
}

template <typename T>
const T& CP::stack<T>::top() {
	// if stack_a is empty , pop_bottom from stack_b (which was top element from stack_a)
	if ((stack_a.empty() == true) && (stack_b.empty() == false)) {
		while (stack_b.empty() == false) { 
			stack_a.push( stack_b.top() ) ; 
			stack_b.pop() ; 
		}
		// pop out stack_a 
		return stack_a.top() ; 
	}
	else if ((stack_a.empty() == false)) { // in case a & b still have data
		// can directly pop a out 
		return stack_a.top() ; 
	}
}

template <typename T>
const T& CP::stack<T>::bottom() {
	// write your code here

	// change all data from stack_a to stack_b 
	// then return top of stack_b (which is stack_a bottom)

	// check if stack_a is empty or not 
	if ((stack_a.empty() == false) && (stack_b.empty() == true)) { 
		// a not empty -> pop then push to b
		// get top of b (which is bottom of a) then put all back to a

		while (stack_a.empty() == false) { 
			stack_b.push( stack_a.top() ) ; 
			stack_a.pop() ; 
 		}

		T& top_element_b = stack_b.top() ; 

		/* no need to push back to a
			while (stack_b.empty() == false) { 
				stack_a.push( stack_b.top() ) ; 
				stack_b.pop() ; 
			}
		*/

		return top_element_b ; 
	}

	else { // a&b not emoty & b not empty
		// a is empty -> return top of b (bottom of a)
		T& top_element_b = stack_b.top() ; 
		return top_element_b ; 
	}

	
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	// write your code here
	stack_b.push(element) ; 

}

template <typename T>
void CP::stack<T>::pop_bottom() {
	// write your code here

	if ((stack_a.empty() == false) && (stack_b.empty() == true)) { 
		
		// change all data from stack_a to stack_b 
		while (stack_a.empty() == false) { 
			stack_b.push( stack_a.top() ) ; 
			stack_a.pop() ; 
		}

		// then pop top element in stack_b
		stack_b.pop() ; 

	}
	else { // a is empty , directly pop top of b (bottom of a) 
		stack_b.pop() ; 
	}

	
}
#endif