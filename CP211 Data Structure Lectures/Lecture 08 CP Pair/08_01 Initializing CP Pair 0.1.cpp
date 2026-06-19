# include <iostream> 
# include <string> 
# include <utility> // pair
using namespace std ; 

// define CP Namespace 
namespace CP {
    // define template 
    template <typename T1 , typename T2>
    // define class (std data structure)
    class pair { 
        public : // T1 , T2 can be accessed
            T1 first ; 
            T2 second ; 
    }; // ; before ending class
}

// main function 
int main() { 
    CP::pair<int , string> p1 , p2 ; // default constructor
    p1.first = 42 ; p1.second = "Nattee" ; 

    CP::pair<int , string> a(p1) ; // copy constructor --> a having p1 values 
        // p1 must be same tyoe as a

    p2 = p1 ; // copy p2 to p1 
    // done on background 
        // p2.first = p1.first then p2.second = p1.second

    cout << p2.first << " " << p2.second << endl ; 

    /*

    // --- Operator Overloading = can't be used now ---
    if (p1 == p2) { //won't compile
    cout << "yes" << endl;
    }

    --- Operator Overloading less than can't be used now ---
    if (p1 < a) { //won't compile
    cout << "yes" << endl;
    }
    */



}
