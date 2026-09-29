#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// NOTE THAT unordered_set is O(1) --> fastest and faster than set (O(log N))

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;

    /* note : using find() in vector takes O(n) , which maybe TLE
    so I fixed by adding element in vector but using find() in std::set instead (takes only O(log N) )
    
        
        // put A in vector first 
        for (auto &each_element : A) { 
            v.push_back(each_element) ; 
        } 
        // check each element in A 
        for (auto &each_element : B) { 
            // find B in vector if already have 
            if (find(v.begin() , v.end() , each_element) == v.end()) { 
                v.push_back(each_element) ; 
            }
        }
    */

    // step 1 : put A in vector first 
    unordered_set<T> found ; 

    for (auto &e : A) {
        v.push_back(e) ; found.insert(e) ; 
    }

    for (auto &e : B) { 
        // check if found in set already 
        if (found.find(e) == found.end()) { 
            // if not found , add element into std::vector v 
            v.push_back(e) ; 
        }
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    // cheat : copy set from vector 
    unordered_set<T> setB = unordered_set(B.begin() , B.end()) ; 

    // logic : loop each element in A 
    // then find if that element exist in B too 

    for (auto &each_element : A) { 
        if (setB.find(each_element) != setB.end()) { 
            v.push_back(each_element) ; 
        } 
    }

    return v;
}
