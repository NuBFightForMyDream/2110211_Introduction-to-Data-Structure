#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
using namespace std ; 

string infix_to_postfix (string &infix)  { 
    // define length of infix 
    int n = infix.length() ; 
    string postfix = "" ; 

    // assign priority to check which operand should do first 
    map<char , int> priority_of_operator_value = { {'+',3} , {'-',3} , {'*',5} , {'/',5} , {'^',7} } ; 

    stack<char> storage ; 

    // loop each data from left to right 
    for (int i = 0 ; i < n ; i++) { 
        // check if that character is infix 
        char each_char = infix[i];
        if (priority_of_operator_value[each_char] == 0) {
            // operand -> not operator --> value from key = 0 
            postfix += each_char ; 
        }

        else { 
            // check priority value
            int p_val = priority_of_operator_value[each_char] ; 
            while ( (storage.empty() == false) && (priority_of_operator_value[storage.top()] >= p_val) ) {
                // still more priority , add top element then pop out 
                postfix += storage.top() ; 

                // pop out 
                storage.pop() ; 

            }
            // push each char to storage
            storage.push(each_char) ; 
        }

    }

    // check left element (in case have remainder operand or operator)
    while (storage.empty() == false) { 
        postfix += storage.top() ;
        storage.pop() ; 
    }

    return postfix ; 
}


int main() { 
    // note : infix = 5+4*3/2^1
           // postfix = 543*21^/+ 

    string infix_test = "5+4*3/2^1" ;
    string postfix_expected ;

    cout << infix_to_postfix(infix_test) << endl ; 
    
}