#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility> // pair
#include <algorithm>
using namespace std ; 

int main() { 
    int count_interval , count_check ; 
    cin >> count_interval >> count_check ; 
    vector< pair<int , int> > all_intervals ; // store all found intervals

    for (int i = 0 ; i < count_interval ; i++) { 
        int left , right ; 
        cin >> left >> right ; 

        all_intervals.push_back( make_pair(left , right) ) ;  
    }
    sort( all_intervals.begin() , all_intervals.end() ) ; 


    // loop intersect intervals 
    vector< pair<int , int> > intervals_cleaned ;
    
    // check size first 
    if (all_intervals.empty()) { 
        return 1 ; 
    }

    // check bound
    int current_left = all_intervals[0].first ; 
    int current_right = all_intervals[0].second ; 

    for (int i = 0 ; i < all_intervals.size() - 1 ; i++) { 
        // if covered , save new value until not covered
        int next_left = all_intervals[i+1].first ;
        int next_right = all_intervals[i+1].second ; 

        if (current_right + 1 >= next_left) { 
            // check max of current_right and next_right
            // current_left = min(current_left , next_left) ; 
            current_right = max(current_right , next_right) ; 
        } 
    
        // otherwise , add value 
        else { 
            intervals_cleaned.push_back( make_pair(current_left , current_right) ) ; 
            // move to current_left & current_right
            current_left = next_left ; 
            current_right = next_right ; 

        }
    }
    // add latest element
    intervals_cleaned.push_back( make_pair(current_left , current_right) ) ; 

    // check value 
    for (int j = 0 ; j < count_check ; j++) { 
        int check_number ; cin >> check_number ; 

        // loop with break check
        // for loop isnt a good way , so using uppr_bound is better
        // use upper bound because we dont want to check value that >= x (which is lower_bound)

        auto current_itr = upper_bound( intervals_cleaned.begin() , intervals_cleaned.end() , make_pair(check_number , check_number) ) ; 
        auto prev_itr = prev(current_itr) ; 


        // case 1 : number out of range 
        if ( (check_number < intervals_cleaned.begin()->first) || (check_number > prev(intervals_cleaned.end())->second) ) {
            cout << "0" << " " ; // not found
        }

        // case 2 : number in interval
        else if ( (check_number > prev_itr->second) && (check_number < current_itr->first) ) { 
            cout << "0" << " " ; // not found
        }

        else { 
            cout << "1" << " " ; // found
        }

    }

    cout << endl ; 

}