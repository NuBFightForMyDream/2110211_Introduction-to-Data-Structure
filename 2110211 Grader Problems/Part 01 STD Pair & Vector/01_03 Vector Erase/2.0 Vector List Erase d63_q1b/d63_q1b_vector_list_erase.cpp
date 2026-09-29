#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void list_erase(vector<int> &v, vector<int> &pos) {
    // define vector of bool for checking which pos to push back
    vector<bool> append_or_not(v.size() , true) ;
    
    // assign pos_to_append to false 
    for (int each_pos : pos) { 
        append_or_not[each_pos] = false ; 
    }
    
    // loop push back element in vector
    vector<int> removed_element_vector ; 
    for (int i = 0 ; i < v.size() ; i++) {
        if (append_or_not[i] == true) {
            removed_element_vector.push_back( v[i] ) ; 
        }
    }
    
    // assign new vector to v
    v = removed_element_vector ; 
    
}
int main() {
     std::ios_base::sync_with_stdio(false);
     cin.tie(0);
     int n,m;
     cin >> n >> m;
     vector<int> v(n), pos(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) cin >> pos[i];
    list_erase(v,pos);
    cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}