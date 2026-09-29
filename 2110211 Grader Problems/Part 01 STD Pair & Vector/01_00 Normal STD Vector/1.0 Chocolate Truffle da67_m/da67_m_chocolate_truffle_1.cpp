# include <iostream> 
# include <vector> 
# include <set> 
# include <algorithm> 
# define ll long long
using namespace std ; 

ll calculate_position(ll row , ll col , ll total_col) {
    // row , col always starts with 1 
    // change position (x,y) as index 0,1,2,3,... for each index
    ll row_org = row - 1 , col_org = col - 1 ;
    return row_org * total_col + col_org ; 
}

int main() {
    // step 1 : input data 
    ll row_choc , col_choc , count_fav_choc ; 
    ll count_start_choc ; 

    cin >> row_choc >> col_choc ; 

    // step 2 : add faourite choc to vector
    vector<ll> favourite_choc ;
    cin >> count_fav_choc ; 
    for (ll i = 0 ; i < count_fav_choc ; i++) { 
        // define data for favourite chocolate
        ll row_fav = 0 , col_fav = 0 ; 
        cin >> row_fav >> col_fav ; 
        // add data
        favourite_choc.push_back( calculate_position(row_fav , col_fav , col_choc) ) ; 
    }

    // step 3 : sort for using lower bound 
    sort(favourite_choc.begin() , favourite_choc.end()) ; 

    // add last element in case have to re-eat at 1 
    favourite_choc.push_back( (row_choc * col_choc) + favourite_choc[0] ) ;

    // step 4 : use lower bound to check how many days to eat 
    cin >> count_start_choc ; 
    for (ll i = 0 ; i < count_start_choc ; i++) { 
        // define input 
        ll row_choc_start , col_choc_start ;
        cin >> row_choc_start >> col_choc_start ;  
        ll pos_start = calculate_position(row_choc_start , col_choc_start , col_choc) ;

        // use lower bound 
        ll days_to_eat = *lower_bound(favourite_choc.begin() , favourite_choc.end() , pos_start) - pos_start ; 
            // lower bound return iterator , so use * to refer real data 
        cout << days_to_eat << endl ; 
    }

}