#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    // define varibale with method inside []
    auto compare = [](const string& lhs, const string& rhs) {
            return lhs.size() < rhs.size();
        };
    
    cout << "Result of compare function = " << compare("xxx","z") << endl; // can call variable dai loei

    // store type string , container "vector<string>" , sort with compare Class (btw it's variable which defining method inside) 
    priority_queue<string,vector<string>,decltype(compare)> pq(compare); // but in pq -> meed to use decltype (declare type)
    pq.push("somchai"); // most priority (length 7)
    pq.push("z");
    pq.push("abc");
    
    // sort priority by length of alphabet 
    while (pq.empty() == false) {
        cout << pq.top() << endl;
        pq.pop();
    }
}