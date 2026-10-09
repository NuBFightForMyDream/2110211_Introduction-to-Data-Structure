#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using ll = long long ; 
using namespace std ; 

int main() { 
    ll count_floor , count_customer ; 
    cin >> count_floor >> count_customer ;

    set<pair<ll , ll>> hotel_available_rooms_info ; 
    ll total_available_room_count = 0 ; 

    // store with set<pair> to store 
    for (ll i = 0 ; i < count_floor ; i++) {
        ll available_room ; cin >> available_room ; 
        // add to total 
        total_available_room_count += available_room ; 
        // 

    }
    for (ll i = 0 ; i < count_customer ; i++) { 

    }
}