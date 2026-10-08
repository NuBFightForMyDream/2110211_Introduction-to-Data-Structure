#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std ; 

int main() { 
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    long long count_girls , count_questions ; 
    cin >> count_girls >> count_questions ; 

    map<long long , long long> tracen_info ; // {power , count}
    
    for (int i = 0 ; i < count_girls ; i++) { 
        long long power ; cin >> power ;
        tracen_info[power]++ ;  
    }

    for (long long i = 0 ; i < count_questions ; i++) { 
        long long operation , count_need , power_need ; 
        cin >> operation >> count_need >> power_need ; 

        // define total_power for each loop 
        long long total_power = 0 ; 

        // do for opeartion 1 , got 60/100
        if (operation == 1) { // easy find 
            // map already sorted 
            // use lower_bound to find nearest power
            
            // loop to find tracen
            for (int j = 0 ; j < count_need ; j++) { 
                // using upper_bound to find value that > power_need (then we will move back iterator 1 step)
                auto it = tracen_info.upper_bound(power_need) ; 
                
                // check if we have some of tracen we need
                // if didn't have , (it = begin) , break then go to next loop
                if (it == tracen_info.begin()) break ; 

                // else , decrease iterator (we'll get best power)
                it-- ; 

                // then add power to total_power 
                total_power += it->first ; 
                // decrease frequency 
                it->second-- ; 
                
                // check if frequency = 0 , if true then delete {key,val}
                if (it->second == 0) {
                    tracen_info.erase(it) ; 
                }
            }
        }
        else { // hard find , more 40/100
            











            
        }
        // get total_power out     
        cout << total_power << "\n" ; 
    }
    

    
}
