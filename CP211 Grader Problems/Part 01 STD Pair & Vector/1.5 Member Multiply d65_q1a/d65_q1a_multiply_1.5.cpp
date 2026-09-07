#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void member_multiply(vector<int> &v, vector<pair<vector<int>::iterator,int>> &multiply) {
    //write your code here

    // Logic : create pos_shift for cumulative rightshift position (in each loop of multiply)

    /*  
    Original : 10 20 30 40 50 

    Mult
    0 (10) 1 
    1 (20) 1 
    2 (30) 1 
    3 (40) 1
    4 (50) 2
    5 (60) 1
    Result
    10 10 20 20 30 30 40 40 50 50 50 60 60

    เเทรกหน้า 
    ->10 20 30 40 50 60  -> b+0 
    10 10 ->20 30 40 50 60 -> b+2
    10 10 20 20 ->30 40 50 60 -> b+4
    10 10 20 20 30 30 ->40 50 60 -> b+6
    10 10 20 20 30 30 40 40 ->50 60 -> b+8
    10 10 20 20 30 30 40 40 50 50 50 -> 60 -> b+11
    10 10 20 20 30 30 40 40 50 50 50 60 60 

    ครั้งเเรก + ตำเเหน่งที่เจอ 
    ครั้งต่อมา + ของเก่าทบมาเรื่อยๆ shift สะสม
    */

    // Step 1 : change all iterator to index (bcz iterator if after insert will be changed every time)
    vector< pair<int , int> > multiply_with_index ; 
    for (auto &each_pair : multiply) { // pair<itr , int> 
        int index = each_pair.first - v.begin() ; 
        multiply_with_index.push_back( {index , each_pair.second} ) ; // push back with pair<int , int>
    }
    // sort vector for command 
    sort( multiply_with_index.begin() , multiply_with_index.end() ) ;

    // Step 1 : define variable before loop 
    int shift = 0 ; 
    // step 2 : get each info for looping in multiply 
    for (int i = 0 ; i < multiply.size() ; i++) { // multiply[i] = {itr_mul , count_repeat)
        int pos = multiply_with_index[i].first ; 
        int count = multiply_with_index[i].second ; 

        int current_pos = pos + shift ; 
        int val = v[current_pos] ; // index current pos bcz vector has shifted size
        
        // insert val to vector 
        // then add pos_shift with 
            // command : vec.insert(pos , count , value) (no need to create vector_for_insert)
        v.insert( v.begin() + current_pos , count , val ) ; 

        // add cumulative 
        shift += count ; 
    }

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m); // vector to be repested 
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        multiply[i].first = v.begin()+a;
        multiply[i].second = b;
    }
 
    member_multiply(v,multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}