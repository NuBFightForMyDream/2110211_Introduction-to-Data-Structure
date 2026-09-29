# include <iostream> 
# include <vector>
using namespace std ; 

void print(vector<int> v) {
    cout << "Size of V is " << v.size() << ": ";
    for (int i = 0;i < v.size();i++) cout << v[i] << ", ";
    cout << endl;
}


int main() { 
    vector<int> v(3,8) ; // vector of 8 with 3 element
    print(v);
    v.insert( v.begin(), 1); // insert at begin with 1
    print(v);
    v.insert( v.begin()+3, 2); // insert at begin+3 with 2
    print(v);
    v.insert( v.end(), 3); // insert at end with 3
    print(v);
    v.pop_back() ; // erase last element
    print(v) ; 
}