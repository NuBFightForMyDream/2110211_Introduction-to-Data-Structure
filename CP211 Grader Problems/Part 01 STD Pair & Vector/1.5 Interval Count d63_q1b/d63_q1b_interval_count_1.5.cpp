# include <iostream> 
# include <algorithm> 
# include <vector> 
# include <set>
# define ll long long
using namespace std ; 

int intervalCountMember(vector<ll> &members , ll gap , ll tofind_val) { 
    // สมมติให้เลขดังกล่าวคือ p เราต้องการทราบว่า ในช่วงปิด [p-k,p+k] มีจํานวนเต็ม
    // ในรายการที่ระบุในข้างต้นจํานวนกี่ตัว 

    // step 1 : define lower_fence & upper_fence
    ll lowerb_val = tofind_val - gap ;
    ll upperb_val = tofind_val + gap ;

    // step 2 : using upper bound & lower bound to find nearest number 
        // because loop in set for counting is too slow 
    auto lowerb_itr = lower_bound(members.begin() , members.end() , lowerb_val) ; // <= p-k
    auto upperb_itr = upper_bound(members.begin() , members.end() , upperb_val) ; // > p+k (not including here)
    
    // step 3 : calculate distance then return 
    ll dist_count = distance(lowerb_itr , upperb_itr) ; 
    return dist_count ; 
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    ll number_count , to_find_count , gap ; 
    cin >> number_count >> to_find_count >> gap ; 

    vector<ll> numbers ; 
        // from problem , no repeated numbers so using set is better choice
        // but but but , using upper_bound & lower_bound in set is fkin slower
    for (ll i = 0 ; i < number_count ; i++) { 
        ll number ; cin >> number ; 
        numbers.push_back(number) ;       
    }

    // sort vector before call function 
    sort(numbers.begin() , numbers.end()) ;

    for (ll j = 0 ; j < to_find_count ; j++) { 
        // input number 
        ll tofind_val ; cin >> tofind_val ; 

        // call intervalCountMember function
        ll num_count = intervalCountMember(numbers , gap , tofind_val) ; 
        cout << num_count << " " ; 
    }
}