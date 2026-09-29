# include <iostream> 
# include <queue>
# include <vector>
using namespace std ; 

int main() { 
    // define queue 
    queue<int> q ; 
    q.push(1) ; q.push(2) ; q.push(3) ; 
    // check element in queue 
    while (q.empty() == false) { 
        cout << q.front() << endl ; 
        // first element will be out (front)
        q.pop() ; // pop first element (front)
    }

    cout << "-- example 2 --" << endl ; 

    // define queue of vector 
    queue< vector<int> > q2 ; 
    vector<int> v1 = {1,2,3} ; 
    vector<int> v2 = {99,88,-1} ; 

    q2.push( v1 ) ; q2.push( v2 ) ; // q2 = front <v1 , v2> back 

    cout << q2.back()[1] << endl ; // equals v2[1] = 88
    cout << q2.front().size() << endl ; // equals v1.size() = 3

    vector<int> frontElement = q2.front() ; // equals v1 = {1,2,3}
    q2.pop() ; // q2 = <v2>
    cout << frontElement[0] << endl ; // v1[0] = 1 
}