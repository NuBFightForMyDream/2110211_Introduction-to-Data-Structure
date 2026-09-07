// Part 00 C++ Intro 
// a59_q1_quicksum (1 Star) : 60% (dumb solution)

# include <iostream> 
# include <vector> 
# include <cmath> 
using namespace std ;

int main() { 
    // input data 
    int row , column , check_count ; 
    cin >> row >> column >> check_count ; 

    // initialize vector with column vector (with count of rows)
    vector<vector<int>> numbers(row, vector<int>(column));
    for (int i = 0 ; i < row ; i++) { 
        for (int j = 0 ; j < column ; j++) { 
            cin >> numbers[i][j] ; 
        }
    }

    // calculate sum 
    for (int i = 0 ; i < check_count ; i++) { 
        int r1 , c1 , r2 , c2 ;
        cin >> r1 >> c1 >> r2 >> c2 ; 

        int summation = 0 ; 

        for (int i = r1 ; i <= r2 ; i++) { 
            for (int j = c1 ; j <= c2 ; j++) { 
                summation += numbers[i][j] ; 
            }
        }

        cout << summation << endl ; 
    }


}
