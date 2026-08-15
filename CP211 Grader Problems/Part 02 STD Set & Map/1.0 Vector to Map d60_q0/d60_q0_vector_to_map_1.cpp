#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
map<int, string> vector_to_map(vector<pair<int, string>>::iterator start, 
    vector<pair<int, string>>::iterator end)
{
    // write your code here
    // you need to declare a map here
    // do not forget to return the map
    // interval will be [start , end)

    map<int , string> converted_v2m ;
    auto current_itr = start ; 
    while (current_itr < end) { 
        // define current key & value
        auto current_key = (*current_itr).first ; 
        auto current_val = (*current_itr).second ; 

        // check if key already exist in map
        if (converted_v2m.count(current_key) <= 0) { 
            // key NOT exist in map , add key:val to map 
            converted_v2m[current_key] = current_val ;  
        }
        
        // else do nothing , skipped
        // dont forget to move iterator
        current_itr++ ; 
    }

    // return converted map
    return converted_v2m ; 

}

int main()
{
    // n = vector size , a = pos to start , b = pos to end 
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, string>> v(n); // vector with size n
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }
    map<int, string> m;
    m = vector_to_map(v.begin() + a, v.begin() + b);
    cout << "-------- result -----------" << endl;
    cout << "Size of map = " << m.size() << endl;
    for (auto &x : m)
    {
        cout << "(" << x.first << "," << x.second << ")" << endl;
    }
}