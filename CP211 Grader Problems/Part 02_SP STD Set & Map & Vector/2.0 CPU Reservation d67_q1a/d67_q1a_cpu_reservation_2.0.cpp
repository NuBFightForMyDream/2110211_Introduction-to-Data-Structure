#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std ;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // logic similar to da66_m1_line_monopoly
    map<int , pair<int,int> > reservation_info ; 
    set<int> id_reserved ; 

    // Part I : input & store data 
    int count_reservation ; cin >> count_reservation ; 
    for (int user_id = 1 ; user_id <= count_reservation ; user_id++) { 
        int start_time , finish_time ; 
        cin >> start_time >> finish_time ; 
        // add data into map
        reservation_info[user_id] = make_pair(start_time , finish_time) ; 
    }

    // Part II : do interval 
    set< pair<int , int> > assigned_interval_time ; 
    int min_left = 0 , max_right = 0 ; 

    // for loop each_id and check interval time
    int uid = 1 ; 
    for (auto &each_info : reservation_info) {

        pair<int,int> current_time_interval = each_info.second ; 

        if (uid == 1) { // first reserve , assign to database
            assigned_interval_time.insert( current_time_interval ) ; 
            id_reserved.insert(uid) ; 

            // assign to border time
            min_left = current_time_interval.first ;
            max_right = current_time_interval.second ; 
        }

        else { 
            // check available interval                  
            auto time_to_check_itr = assigned_interval_time.lower_bound(current_time_interval);

            // define boolean of available or not 
            bool available_to_reserve = true ; 

            // check if not out of bound
            if (time_to_check_itr != assigned_interval_time.begin()) { 
                // not out of bound , check current_left with before_right 

                auto time_to_check_prev_itr = prev(time_to_check_itr) ; 

                if ( !(time_to_check_prev_itr->second < current_time_interval.first) ) { 
                    available_to_reserve = false ; 
                }
            }

            if (time_to_check_itr != assigned_interval_time.end()) { 
                // not out of bound , check current_right with next_left 

                if ( !(current_time_interval.second < time_to_check_itr->first) ) { 
                    available_to_reserve = false ; 
                }
            }

            // if still available , add data 
            if (available_to_reserve == true) { 
                assigned_interval_time.insert( current_time_interval ) ; 
                id_reserved.insert(uid) ; 
            }
            

        }
    
        uid++ ; // add uid every time

    }

    // output 
    for (auto &each_uid : id_reserved) cout << each_uid << " " ; 
    cout << endl ; 
    
}