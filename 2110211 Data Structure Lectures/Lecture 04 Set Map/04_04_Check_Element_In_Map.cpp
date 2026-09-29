#include <iostream>
#include <map>
using namespace std;

int main() {
    //map between "Key Type" string and "Mapped Type" int
    map<int,string> m;
    m[1] = "somchai";
    m[99] = "nattee"; // now m = { {1,"somchai"} , {99,"nattee"} } 
    int k = 99;

    // define map iterator
    map<int,string>::iterator it; // cant use auto 
    if ((it = m.find(k)) != m.end()) { // find data then check if not end
        // find with key
        cout << "Key " << it->first << " is mapped to " << it->second << endl;
    } 
    else {
        cout << "Key " << k << " is not exists in m." << endl;
    }

    //this is not the correct way to check if key exists why??
    if (m[k] != "") { // "" is not default value -> auto generated data (added)
        cout << "exists" << endl; // use find() instead
    } 
    else {
        cout << "does not exists" << endl;
    }

    // map will sort key automatically (not sorting value)
}
