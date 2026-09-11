# include <iostream> 
# include <algorithm> 
# include <vector> 
# include <utility> 
# include <map> 
using namespace std ; 

int main() { 
    // input data as vector 
    vector< pair<int,int> > number_and_order ; 
    
    int N ; cin >> N ;
    for (int i = 1 ; i <= N ; i++) { 
        int num ; cin >> num ; 
        number_and_order.push_back( make_pair(num , i) ) ; 
    }

    // sort vector for order
    vector< pair<int,int> > number_and_order_sorted ; number_and_order_sorted = number_and_order ; //copy vector 
    sort( number_and_order_sorted.begin() , number_and_order_sorted.end() ) ; 

    // store old and new order into map 
    map<int , int> old_and_new_order ; 
    for (int i = 0 ; i < N ; i++) { 
        int old_order = number_and_order[i].second ; 
        int new_order = number_and_order_sorted[i].second ; 
        old_and_new_order[new_order] = old_order ; // new_order (sort order) -> old_order (sort value)
    }

    // check old order from old vector then print new order
    for (int i = 0 ; i < N ; i++) { 
        auto old_order = number_and_order[i].second ; // pair<int , int>
        int new_order = old_and_new_order[old_order] ; 
        cout << new_order << " " ; 
    }
}