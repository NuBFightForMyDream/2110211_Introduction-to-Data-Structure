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


    // two iterator
    long long left = 0 , right = dance_difference.size() - 1 ; 
    while (left < right) { 
        
    }






}