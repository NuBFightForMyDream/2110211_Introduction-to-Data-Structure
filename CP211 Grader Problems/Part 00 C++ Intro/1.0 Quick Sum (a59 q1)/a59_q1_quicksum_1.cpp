// Part 00 C++ Intro 
// a59_q1_quicksum (1 Star) : 100% solution

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

    // define prefix_sum matrix 
    vector<vector<int>> prefix_sum = numbers ; // copy matrix 

    // define first top-left element
    prefix_sum[0][0] = numbers[0][0] ; 

    // step 1 : consecutive sum for each column 
    for (int c = 1 ; c <= column - 1 ; c++) { 
        prefix_sum[0][c] = prefix_sum[0][c-1] + numbers[0][c] ; 
        // formula : current_col = prev_col + num_at_this_pos
    }

    // step 2 : consecutive sum for each row
    for (int r = 1 ; r <= row - 1 ; r++) { 
        prefix_sum[r][0] = prefix_sum[r-1][0] + numbers[r][0] ; 
        // formula : current_row = prev_row + num_at_this_pos

        // step 3 : calculate targeted value 
        
        for (int c = 1 ; c <= column - 1 ; c++) { 
            // define value for easier understanding
            int top = prefix_sum[r-1][c] ; 
            int left = prefix_sum[r][c-1] ; 
            int top_left_repeated = prefix_sum[r-1][c-1];
            int num_that_pos = numbers[r][c] ; 

            prefix_sum[r][c] = (top + left - top_left_repeated) + num_that_pos ; 
        }
    }

    // step 3 : reframe value from input 
    for (int k = 0 ; k < check_count ; k++) { 
        int r1 , c1 , r2 , c2 ; 
        // (r1,c1) = top-left corner , (r2,c2)  = bottom_right corner
        cin >> r1 >> c1 >> r2 >> c2 ; 

        // get value from prefix sum they display out
        // don't forget to delete some number out (top & left)

        // !!! remember that prefix_sum calculate all ossible values from (0,0) !!!
        // so we need to delete some outside-frame numbers (same algorithm of line 45)

        // delete each section 
        int ans = prefix_sum[r2][c2]; // all 

        if (r1 > 0) ans -= prefix_sum[r1 - 1][c2]; // - top
        if (c1 > 0) ans -= prefix_sum[r2][c1 - 1]; // - left 
        if (r1 > 0 && c1 > 0) ans += prefix_sum[r1 - 1][c1 - 1]; // + top_left

        cout << ans << endl ; 
    }

}