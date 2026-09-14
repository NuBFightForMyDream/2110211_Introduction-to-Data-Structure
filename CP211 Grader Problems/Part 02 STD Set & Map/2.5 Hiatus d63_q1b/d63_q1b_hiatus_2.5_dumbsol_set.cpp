#include <iostream> 
#include <vector> 
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

// Got 50% using set -> Maybe its not work
int main() {
	// input data 
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int count_published , count_check ; 
    cin >> count_published >> count_check ; 
    
    // store data in set 
    set< pair<int , int> > year_month_published ; 
    for (int i = 0 ; i < count_published ; i++) { 
        int y , m ; cin >> y >> m ;
        pair<int , int> data = make_pair(y,m) ; 
        year_month_published.insert( data ) ; 
    }
    
    // set will sort automatically 
    
    
    // now , we'll input then check month with lower bound 
    for (int j = 0 ; j < count_check ; j++) { 
    
        int year_check , month_check ; 
        cin >> year_check >> month_check ; 
        
        // lower bound to check nearest month 
        pair<int , int> pair_to_check = make_pair(year_check , month_check) ; 
        auto latest_published_itr = (lower_bound(year_month_published.begin(), year_month_published.end(), pair_to_check)) ; // move to previous itr later
        
        // check case
        
        // case 1 : year check before year published -> RETURN -1 -1
        if (*latest_published_itr == *year_month_published.begin() && *latest_published_itr != pair_to_check) {
           // don't forget that shouldn't be year/month published for begin iterator
            cout << "-1 -1" << " " ; 
        }
        
        // case 2 : current_check is in year published , RETURN 0 0
        else if (*latest_published_itr == pair_to_check) { 
            cout << "0 0" << " " ; 
        }
        
        // case 3 : general case , move to previous itr then answer
        else { 
            latest_published_itr-- ; // this is the latest published itr
            cout << (latest_published_itr)->first << " " << (latest_published_itr)->second << " " ;  
        }
    }
}
