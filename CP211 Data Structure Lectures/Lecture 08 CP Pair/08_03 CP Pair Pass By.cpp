# include <iostream>
using namespace std ;

// define function of passing by 
void test(int &x , const int &y) {
    x++ ; // OK ; do_able
    cout << y << endl ; // only read y , OK 
    for (int i = 0 ; i < y ; i++) { 
        cout << i << endl ; 
    }
    // y-- ; // not to change Y
}

void pass_by_value(int x) { 
    cout << "X is " << x << endl ; 
    x = 30 ; // x won't change
}

void pass_by_reference(int &x) { 
    cout << "X is " << x << endl ; 
    x = 40 ; // x will change
}

int main() { 
    cout << "Pass by Value, direct" << endl;
    pass_by_value(10);
    cout << endl;

    int x = 20;
    cout << "Pass by value, variable" << endl;
    pass_by_value(x);
    cout << "outside PbR function x = " << x << endl;
    cout << endl;

    cout << "Pass by reference" << endl;
    pass_by_reference(x);
    cout << "outside PbR function x = " << x << endl;
    
    //the following line cannot be compiled
    //because we need reference
    //pass_by_reference(20);
}