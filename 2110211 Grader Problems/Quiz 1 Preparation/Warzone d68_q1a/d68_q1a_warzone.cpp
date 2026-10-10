# include <iostream> 
# include <vector> 
# include <set>
# include <utility>
# include <algorithm> 
using namespace std ; 

int main() { 
    // use this for faster cin / cout 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

    // input data 
    int population , count_boom ; 
    cin >> population >> count_boom ; 

    // define vector<pair> for interval boomed range
    vector< pair<int,int> > bombed_interval ; 
    
    
    // loop
    for (int round_boom = 0 ; round_boom < count_boom ; round_boom++) { 
        int left_position , right_position ; // will check each round and change
        cin >> left_position >> right_position ;
        
        // input new interval every time
        bombed_interval.push_back( make_pair(left_position,right_position) );
        // sort vector
        sort(bombed_interval.begin() , bombed_interval.end() ) ;
        
        // merge interval 
        vector< pair<int,int> > merged ; 
        
        for (auto each_interval : bombed_interval) { 
            if (merged.empty() || merged.back().second < each_interval.first) { // .back = last element
                merged.push_back(each_interval) ; 
            } else {
                merged.back().second = max(merged.back().second, each_interval.second);
            }
            
        }
        bombed_interval = merged ; 
        

        // calculate population left 
        int destroyed = 0;
        for (auto interval : bombed_interval) {
            destroyed += (interval.second - interval.first + 1);
        }

        cout << population - destroyed << "\n";
        
    }
}
