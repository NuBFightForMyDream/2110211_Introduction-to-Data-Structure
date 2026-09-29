# include <iostream> 
# include <vector>
# include <algorithm>
using namespace std ;

int main() { 
    // --------------- Part 1 : find (a,b,c) method ---------------
    vector<int> v = {9,-1,3,7,5,2,1,4};
    int x = 5;
    if ( find(v.begin(), v.end(), x) != v.end() ) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }
    if (find(v.begin(), v.begin()+3, 3) != v.begin()+3) cout << "FOUND" << endl; // found at v.begin() + 2
    //how many "YES" will be printed? (CHEAT QUESTION)
    if (find(v.begin() , v.begin()+2, x) != v.end()) cout << "YES" << endl; // not found , at begin+2 -> YES
    if (find(v.begin() , v.begin()+4, x) != v.end()) cout << "YES" << endl; // not found , at begin+4 -> YES
    if (find(v.begin()+4, v.begin()+2, x) != v.end()) cout << "YES" << endl; // normally , return first = begin+4 -> YES
    if (find(v.begin()+4, v.begin()+8, x) != v.end()) cout << "YES" << endl; // found at begin+4 -> YES

    // --------------- Part 2 : Iterator ---------------
    vector<int> v1 = {0, 10, 20 ,30, 40, 50, 60, 70, 80};
    vector<float> v2 = {0.2, -4, 0.13, 3.14, 2.73};
    cout << "----v1----" << endl;
    auto it = v1.begin();
    while (it < v1.end() ) {
        cout << it - v1.begin() << ": " << *it << endl; 
        // it - v.gein() = index , *it = refer to value
        it++;
    }
    cout << "----v2----" << endl;
    for (auto it = v2.begin(); it < v2.end(); it++) {
        cout << it - v2.begin() << ": " << *it << endl;
    }

    // --------------- Part 3 : Max Element & Min Element ---------------
    vector<int> v3 = {3,0,1,2,4,-3,9,8};
    vector<float> v4 = {10.2, -4, 0.13, 3.14, 2.73};
    auto it1 = min_element(v3.begin(),v3.end()); // check all element 
    auto it2 = max_element(v4.begin()+2,v4.end()); // check only in this range 
    cout << "Min Element : " << *it1 << endl;
    cout << "Max Element in range : " << *it2 << endl;

    // --------------- Part 4 : Lower Bound & Upper Bound ---------------
    vector<int> numbers = {10,20,40,80,160,320,640,1280};
    int num_to_find = 160 ; 

    // find lower bound & upper bound iterator
    auto lowerb_itr = lower_bound(numbers.begin() , numbers.end() , num_to_find) ; // first pos for >= val
    auto upperb_itr = upper_bound(numbers.begin() , numbers.end() , num_to_find) ; // first pos for > val
    cout << "Lower Bound Value : " << *lowerb_itr << " --> Upper Bound Value : " << *upperb_itr << endl ;  

    // find pos with distance(...) cmd 
    int pos_lowerb = distance(numbers.begin() , lowerb_itr); // index 4 from begin
    int pos_upperb = distance(numbers.begin() , upperb_itr); // index 5 from begin

    cout << "Index of Lower Bound : " << pos_lowerb << " --> Index of Upper Bound : " << pos_upperb << endl ;  

    // Note : reference to real value with "&"
}
