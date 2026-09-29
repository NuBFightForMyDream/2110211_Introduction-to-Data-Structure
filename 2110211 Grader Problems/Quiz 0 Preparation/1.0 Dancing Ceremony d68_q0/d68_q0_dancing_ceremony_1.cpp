#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std ; 

int main() { 
    long long count_couple ; cin >> count_couple ; 
    vector<long long> dance_ability_a ; 
    vector<long long> dance_ability_b ; 

    // push data into vector
    for (long long i = 0 ; i < count_couple ; i++) {
        long long dance_a ; cin >> dance_a ; 
        dance_ability_a.push_back(dance_a) ; 
    }
    for (long long i = 0 ; i < count_couple ; i++) {
        long long dance_b ; cin >> dance_b ; 
        dance_ability_b.push_back(dance_b) ; 
    }

    // calculate difference_dance
    vector<long long> dance_difference ; 
    for (long long i = 0 ; i < count_couple ; i++) { 
        dance_difference.push_back( dance_ability_a[i] - dance_ability_b[i] )  ; 
    }

    // sort dance_difference first
    sort(dance_difference.begin() , dance_difference.end()) ; 

    long long perfect_pair_couples = 0 ; 
    
    for (long long i = 0 ; i < dance_difference.size() ; i++) { // btw we can use 2-pointer to solve this problem
        // find upper_bound iterator then sum distance with latest element (which having value) [caution of : > 0 -> > is upper_bound]
        auto current_itr = upper_bound(dance_difference.begin() + i + 1 , dance_difference.end() , -dance_difference[i]) ; // start finding at j (i+1)
            // from equation : diff[i] + diff[j] > 0 -> we're finding diff[j] so , diff[j] > 0 - diff[i] (which means that we're finding upper_bound on -diff[i])
        // find distance
        auto count_perfect = distance(current_itr , dance_difference.end()) ; 
        perfect_pair_couples += count_perfect ; 
    }

    cout << perfect_pair_couples << endl ; 

}