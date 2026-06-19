# include <iostream> 
# include <queue> 
# include <algorithm>
using namespace std ; 


// function for overloading normal operator 
// name method with "operator" and sign "+/-/*/..." like "operator+"
string operator*(string &lhs , const int &rhs) { // must be const too 
    // lhs represent string , rhs represents count of consecutive words
    string result = "" ; 
    for (int i = 0 ; i < rhs ; i++) { 
        result = result + lhs ; 
    }
    return result ; 
}

int main() { 
    string a = "abc ";
    cout << a * 3 << endl;
    //this gives "abc abc abc "
}
