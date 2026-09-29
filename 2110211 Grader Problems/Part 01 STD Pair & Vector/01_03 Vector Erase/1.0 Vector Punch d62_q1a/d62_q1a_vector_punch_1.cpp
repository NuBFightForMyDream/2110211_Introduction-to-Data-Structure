#include <iostream>
#include <vector>
using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    // write some code here
    // don’t forget to return something
    
    // 1 : define left & right bound 
    // check distance if out of bound -> it = v.begin() + j ;
    vector<string>::iterator left_bound , right_bound ; 
    if ( distance(v.begin() , it) <= k ) left_bound = v.begin() ; 
    else left_bound = it - k ; 

    if ( distance(it , v.end()) <= k ) right_bound = v.end() ; 
    else right_bound = it + k + 1 ; 
    
    // 2 : delete with iterator
    v.erase(left_bound , right_bound) ;  

    return v ; 
    
}
int main() {
    // input info 
    int n,j,k;
    cin >> n >> j >> k;
 
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
 
    cout << "Result after punch" << endl;
    
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
    }
}