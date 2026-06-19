# include <iostream> 
# include <string> 
using namespace std ; 

class ccc {
    public:
        int a,b;

        void inspect() const { // This function promises NOT to change anything
            if (a < b) cout << "yes" << endl; // Okay
            // b += 20; // <--- NOT OKAY
        }
        void mutate() { // This function might change something
            if (a < b) a += 10; // Okay
        }
    
    

    void test2(ccc& changeable, const ccc& unchangeable)
    {
        changeable.inspect(); // Okay: doesn't change a changeable object
        changeable.mutate(); // Okay: changes a changeable object
        unchangeable.inspect(); // Okay: doesn't change an unchangeable object
        // unchangeable.mutate(); // ERROR: attempt to change unchangeable object
    }
};