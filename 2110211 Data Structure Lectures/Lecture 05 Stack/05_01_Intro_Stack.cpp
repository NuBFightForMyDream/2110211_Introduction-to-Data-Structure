# include <stack> 
# include <iostream> 
# include <utility> // pair 
# include <algorithm>
# include <string> 
using namespace std ; 

int main() { 
    /* Basic Commands 
    ==> s.size() , s.empty() , s.push(T data) , s.pop() , s.top() 
    */

    // define stack
    stack<int> my_stack ; 
    cout << my_stack.size() << endl ; // check size 

    // add data (push)
    my_stack.push(10); 
    my_stack.push(20);
    my_stack.push(30);

    // see top (stack must not be empty , otherwise will call error)
    while (my_stack.empty() == false) { 
        cout << my_stack.top() << endl ; 
        my_stack.pop() ; // get last element out 
    }

    cout << "-- example 2 --" << endl ; 

    // stack can contains pair inside
    stack< pair<int,string> > s2 ; 
    s2.push( {6 , "Somchai"} ) ; 
    s2.push( {115 , "Nattee"} ) ; 

    // see top element 
    cout << s2.top().first << endl ; // 115
    cout << s2.top().second << endl ; // Nattee

    pair<int,string> top_data = s2.top() ; 
    s2.pop() ; 
    cout << top_data.first << endl ; // 115 

}