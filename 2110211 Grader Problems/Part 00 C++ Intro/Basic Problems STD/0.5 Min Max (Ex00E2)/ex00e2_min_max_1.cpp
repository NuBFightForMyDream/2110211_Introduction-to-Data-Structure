// Min Max (Exe002) : 1 Star

# include <iostream>
# include <iomanip>
# include <algorithm>
# include <string>
using namespace std ; 

int main() {
    // input info 
    int row_total , col_total ; cin >> row_total >> col_total ; 
    int check_round ; cin >> check_round ; 

    // 1 : input matrix then store into 2d array
    int full_matrix[row_total][col_total] ; 

    for (int row = 0 ; row < row_total ; row++) {
        for (int col = 0 ; col < col_total ; col++) {
            cin >> full_matrix[row][col] ; 
        }
    }

    // 2 process : check boundary 
    for (int round = 0 ; round < check_round ; round++) {
        // input boundary to check 
        int r1 , c1 , r2 , c2 ; 
        cin >> r1 >> c1 >> r2 >> c2 ; 

        // case 1 : invalid
        if ( (r1 > r2) || (c1 > c2) ) {
            cout << "INVALID" << endl ; 
        }

        // case 2 : outside (dont forget to minus 1 for index)
            // (r-1 , c-1) is index , so use (r1,c1) instead
        else if ( (r2 < 1) || (c2 < 1) || (r1 > row_total) || (c1 > col_total) ) {
            // top_left is < pos(1,1) , bottom_right > pos(row,col)
            cout << "OUTSIDE" << endl ; 
        }

        // case 3 : general (intersect and valid)
        else {
            // decrease bound first
            r1 = max(r1 , 1) ; // top-left (compare outer(negative) and 1)
            c1 = max(c1 , 1) ;
            r2 = min(r2 , row_total); // bottom-right (compare outer(positive) and row_total)
            c2 = min(c2 , col_total);

            // given first value as maximum value
            int max_val = full_matrix[r1 - 1][c1 - 1] ; // first value is min 

            // for loop , check max 
            for (int i = r1-1 ; i < r2 ; i++) { // start from index until check row
                for (int j = c1-1 ; j < c2 ; j++) { // start from index until check col
                    // for loop check if value > min 
                    if (full_matrix[i][j] > max_val) {
                        max_val = full_matrix[i][j] ;  
                    }
                }
            }

            // print each maximum value
            cout << max_val << endl ; 
        }
    }
}