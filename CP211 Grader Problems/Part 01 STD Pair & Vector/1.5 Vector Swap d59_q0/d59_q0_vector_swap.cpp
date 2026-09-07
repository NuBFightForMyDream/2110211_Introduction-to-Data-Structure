#include <iostream>
#include <vector>
using namespace std;

// function of vector swap 
void vector_swap(vector<int> &v1,vector<int> &v2, int start1, int end1, int start2, int end2) {
    // copy vector from original (only in range we want)
    vector<int> sliced_v1(v1.begin() + start1 , v1.begin() + end1) ; 
    vector<int> sliced_v2(v2.begin() + start2 , v2.begin() + end2) ; 

    // erase old data with range
    v1.erase( v1.begin() + start1, v1.begin() + end1 ) ;
    v2.erase( v2.begin() + start2, v2.begin() + end2 ) ;
    
    // insert vector with new data
    v1.insert( v1.begin() + start1 , sliced_v2.begin() , sliced_v2.end() ) ; // insert at pos ... with sliced_vector
    v2.insert( v2.begin() + start2 , sliced_v1.begin() , sliced_v1.end() ) ; 
    
}
int main() {
    //read input
    int n,c;
    vector<int>v1,v2;

    // input vector 1 
    cin >> n; //number of v1
    for (int i = 0;i < n;i++) {
    cin >> c;
    v1.push_back(c);
    }

    // input vector 2
    cin >> n; //number of v2
    for (int i = 0;i < n;i++) {
    cin >> c;
    v2.push_back(c);
    }

    // input start & end 
    int s1,e1,s2,e2; //position
    cin >> s1 >> e1 >> s2 >> e2;

    //call the function
    vector_swap(v1,v2,s1,e1,s2,e2);

    //display content of the stack
    cout << "v1 has " << v1.size() << endl;
    for (auto &x : v1) { cout << x << " "; }
    cout << endl;

    //display content of the stack
    cout << "v2 has " << v2.size() << endl;
    for (auto &x : v2) { cout << x << " "; }
    cout << endl;
}