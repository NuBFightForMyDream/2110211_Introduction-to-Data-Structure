#include <iostream>
#include <set>
using namespace std;
int main() {
    // define data
    set< pair<string,int> > s = { {"somchai",5},
                                    {"abc",6}, {"abcd",-3}, {"somchai",-4},
                                    {"z",0}, {"z", -1}, {"z",9} };
    
    // print each pair of data
    for (auto &x : s) {
        cout << x.first << "," << x.second << endl;
    }

    cout << "-- find -- " << endl;
    // find pair if found or not 
    auto it = s.find( {"z",-1});

    cout << (*it).first << "," << (*it).second << endl;
    it--; it--; // note : itr is not always same as before

    cout << it->first << "," << it->second << endl; 
    it++; // move to next element 

    cout << it->first << "," << it->second << endl;
}