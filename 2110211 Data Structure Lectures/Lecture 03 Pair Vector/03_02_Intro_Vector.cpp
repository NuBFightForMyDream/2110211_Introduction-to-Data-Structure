# include <iostream> 
# include <vector> 
# include <string>
using namespace std ; 

int main() {
    vector<int> v1 ; 
    cout << v1.size() << endl ; 
    
    vector<int> v2 = {3,4,5} ;
    cout << v2[1] << " " << v2[2] << endl ; 
    
    v1.push_back(67) ; 
    cout << "Now v1 is : " << v1[0] << " which have size " << v1.size() << endl ; 
}