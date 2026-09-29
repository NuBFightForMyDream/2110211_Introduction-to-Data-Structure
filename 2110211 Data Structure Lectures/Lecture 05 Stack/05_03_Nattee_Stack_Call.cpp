# include <iostream>
# include <stack> 
using namespace std ; 

// define function 

/* Stack of this function 
    -- Top --
    test(x = 0) -> do test(x = 1) then pop itself out 
    test(x = 1) -> x = 1 -> popped
    test(x = 2) -> x = 2 -> popped
    test(x = 3) -> x = 3 -> popped 
    test(x = 4) -> x = 4 -> popped
    main() 

    Note that x is all different from each function 
    -- Bottom --
*/
void test(int x) { // recursive function 
    if (x > 0) { 
        int y = x - 1 ; 
        cout << "I am test(" << x << ") continue ..." << endl ; 
        test(y) ; 
        cout << "Now x is " << x << endl ; 
    }
    else { 
        cout << "I am test(0) stop ..." << endl ; 
    }
}

void b(int x) { 
    ++x ; 
}

void a(int x , int y) { 
    int z = x / y ; 
    b(z) ; 
}

int main() { 
    test(4) ; 
    return 0 ; 
}

