#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // pair
using namespace std ; 

int main() { 
    // input data 
    int count_draw ; cin >> count_draw ; 
    vector< pair<int , int> > painted_info ; 

    for (int i = 0 ; i < count_draw ; i++) {
        int left_pos , right_pos ; 
        cin >> left_pos >> right_pos ;

        // create pair for storing info 
        painted_info.push_back( make_pair(left_pos , right_pos) ) ; 
    }

    // algorithm : get all info into 1 vector<pair> then calculate interval
    sort( painted_info.begin() , painted_info.end() );

    // check n-1 pair ( 1-2 , 2-3 , 3-4 , ... , (n-1)-n )

    // define left & right position first
    int current_left = painted_info[0].first ;
    int current_right = painted_info[0].second ; 

    for (int pos = 0 ; pos < painted_info.size() - 1 ; pos++) { 
        // define next value
        int next_left = painted_info[pos + 1].first ; 
        int next_right = painted_info[pos + 1].second ; 

        // 2 case : interval cover or not 

        // case 1 : covered , update current_right
        if (next_left <= current_right + 1) { 
            // update current_right (but check with max function
            current_right = max( next_right , current_right ) ; 
        } 

        // case 2 : not covered , print old interval then update current_interval
        else { 
            cout << current_left << " " << current_right << " " ; 
            // update value
            current_left = painted_info[pos + 1].first ; 
            current_right = painted_info[pos + 1].second ; 
        } 
    }

    // dont forget to add latest value 
    cout << current_left << " "  << current_right << " " ; 
}