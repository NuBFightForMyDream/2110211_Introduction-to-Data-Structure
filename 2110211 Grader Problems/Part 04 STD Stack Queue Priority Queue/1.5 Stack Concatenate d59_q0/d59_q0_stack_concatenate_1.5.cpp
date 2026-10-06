#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void stack_concat(stack<int> &s1, stack<int> &s2) {
    //write your code only in this function
    // stack s1 as top , s2 as bottom 
    
    // define reversed_stack 
    stack<int> reversed_stack_1 ;
    stack<int> reversed_stack_2 ; 

    while (!s1.empty()) { 
        reversed_stack_1.push( s1.top() );
        s1.pop() ; 
    }
    while (!s2.empty()) { 
        reversed_stack_1.push( s2.top() );
        s2.pop() ; 
    }

    // put s2 then s1
    stack<int> concat ; 
    while (!reversed_stack_2.empty()) { 
        concat.push(reversed_stack_2.top()) ; 
        reversed_stack_2.pop() ;
    }
    while (!reversed_stack_1.empty()) { 
        concat.push(reversed_stack_1.top()) ; 
        reversed_stack_1.pop() ;
    }

    // now s1 has data , s2 is empty
    s1 = concat ; 

}
int main() {
    //read input
    int n,m;
    int c;
    cin >> n >> m;
    stack<int> s1,s2;
    for (int i = 0;i < n;i++) {
        cin >> c;
        s1.push(c);
    }
    for (int i = 0;i < m;i++) {
        cin >> c;
        s2.push(c);
    }

    //call the function
    stack_concat(s1,s2);

    //display content of the stack
    cout << "S1 has " << s1.size() << endl;
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    //display content of the stack
    cout << "S2 has " << s2.size() << endl;
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}