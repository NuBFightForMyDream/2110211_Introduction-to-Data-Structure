#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std ;

// define function for fixing bound algorithm
void update_bought_interval_algorithm(set< pair<int,int> > &bought) { 
    // Logic same as da66_m1_line_paint

    // this vector is used for temporary data (which will replace when checking algorithm ended)
    set< pair<int,int> > temp ; 

    if (bought.empty()) {
        return;
    }

    int current_left = bought[0].first ; 
    int current_right = bought[0].second ; 

    for (size_t pos = 0 ; pos < bought.size() - 1 ; pos++) { 
        int next_left = bought[pos + 1].first ; 
        int next_right = bought[pos + 1].second ; 

        // if covered , change interval
        if (next_left <= current_right + 1) { 
            current_right = max(next_right , current_right) ; 
        }

        else { 
            temp.insert( make_pair(current_left , current_right) ) ;
            // update value
            current_left = bought[pos + 1].first ; 
            current_right = bought[pos + 1].second ; 
        }
    }

    // dont forget to add latest value
    temp.insert( make_pair(current_left , current_right) ) ;

    // replace vector with temp
    bought = temp ;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // input data
    int count_check ; cin >> count_check ; 
    set< pair<int,int> > bought_interval ; 

    for (int i = 0 ; i < count_check ; i++) {
        // check command : buy (1) or check (2)
        int command ; cin >> command ; 

        if (command == 1) { // buy
            int left , right ; 
            cin >> left >> right ; 
            
            // add item to bought_range
            bought_interval.push_back( make_pair(left,right) ) ; 
        }

        else if (command == 2) { // check
            // sort interval first 
            // sort( bought_interval.begin() , bought_interval.end() ) ; 

            // call update_bought_interval_algorithm function since "check" is called
            update_bought_interval_algorithm(bought_interval) ; 

            // print size out 
            cout << bought_interval.size() << "\n" ; 
        }
    }
    
}