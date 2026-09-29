#include <iostream> 
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std ; 

int main() { 
    long long count_goat ; cin >> count_goat ;
    vector<long long> goat_position ; 

    // input data into vector
    for (long long i = 0 ; i < count_goat ; i++) { 
        long long pos ; cin >> pos ; 
        goat_position.push_back( pos ) ;  
    } 
    // sort goat_position 
    sort(goat_position.begin() , goat_position.end()) ; 

    // input wolf data
    long long count_wolf ; cin >> count_wolf ; 
    for (long long i = 0 ; i < count_wolf ; i++) { 
        long long wolf_pos ; cin >> wolf_pos ; 

        // check nearest distance to eat
        auto nearest_itr = lower_bound(goat_position.begin() , goat_position.end() , wolf_pos); 
        // shouldnt use prev() bcz prev(begin) can cause error

        // case 1 : out of bound (left) 
        if (nearest_itr == goat_position.begin()) { 
            cout << abs( wolf_pos - *nearest_itr ) << endl ; 
        } 
        else if (nearest_itr == goat_position.end()) {
            cout << abs( wolf_pos - *(nearest_itr - 1) ) << endl ; // use end-1 for last element
        }
        else {
            // data is between left and right 
            auto nearest_left = prev(nearest_itr) , nearest_right = nearest_itr ; 

            // check distance which one is closer
            auto dist_left = abs(wolf_pos - *nearest_left) , dist_right = abs(wolf_pos - *nearest_right) ; 

            if ( dist_left < dist_right ) { // closer to left : dist_left < dist_right
                cout << dist_left << endl ; 
            } 

            else { 
                cout << dist_right << endl ;
            }
        }
        
    }
}