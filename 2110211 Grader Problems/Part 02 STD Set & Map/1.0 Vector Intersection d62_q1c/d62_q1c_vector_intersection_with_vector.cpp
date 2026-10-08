# include <iostream> 
# include <algorithm>
# include <vector>
using namespace std ; 

int main() {

    // Step 1 : input all infos 
        // input n,m
    int N , M ; // N for vector 1 , M for vector 2 
    cin >> N >> M ; 
    
        // define array 
    vector<int> vector_1 ; 
    vector<int> vector_2 ; 
        // input then push back with loop 
    for (int i = 0 ; i < N ; i ++) {
        int val ; cin >> val ;
        vector_1.push_back(val) ;  
    }
    for (int j = 0 ; j < M ; j++) {
        int val ; cin >> val ;
        vector_2.push_back(val);  
    }
    
    // Step 2 : sort vector ascending
    sort(vector_1.begin() , vector_1.end()); // sort with iterator
    sort(vector_2.begin() , vector_2.end());

    // Step 3 : loop then check if same
    vector<int> intersected ;
    
        // define pos (iterator)
    int a = 0 , b = 0 ; 

    while ( a < vector_1.size() && b < vector_2.size() ) {
        // check if data same
        if (vector_1[a] == vector_2[b]) {

            // only add if it doesn't already exist (find from begin o end with val)
            if (find(intersected.begin(), intersected.end(), vector_1[a]) == intersected.end()) {
                intersected.push_back( vector_1[a] );

            }

            // add pos on vector_1 and vector_2
            a++ ; 
            b++ ;  
        }
        else if (vector_1[a] < vector_2[b]) {
            // add pos of vector_1
            a++ ; 
        }
        else {
            // add pos to vector_2
            b++ ; 
        }
    }

    // Step 4 : print intersected vector
    if (intersected.size() > 0)  {
        for (int k = 0 ; k < intersected.size() ; k++) {
            cout << intersected[k] << " " ; 
        }
        cout << endl ; 
    }

    cout << endl ; 
}