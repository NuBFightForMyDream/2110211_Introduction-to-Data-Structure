#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std ; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    long long count_change , count_check , start_rate ; 
    cin >> count_change >> count_check >> start_rate ; 

    // input saving data 
    map<long long , long long> rate_change_history  = { {0,start_rate} }; 
    map<long long , long long> total_savings = { {0,start_rate} };

    // define variable for storing data 
    long long latest_rate = start_rate , latest_day = 0 ; 
    long long cumulative_savings = 0 , current_total = start_rate ; 

    for (long long i = 0 ; i < count_change ; i++) { 
        long long day_change, rate_change;
        cin >> day_change >> rate_change;

        // calculate days_between
        long long days_between = (day_change - 1 - latest_day) ; // not including today
        cumulative_savings = days_between * (latest_rate) ; 
        
        // add cumulatve_savings to curent_total and map
        current_total += (rate_change + cumulative_savings) ; 
        total_savings[ day_change ] = current_total ; 

        // update latest rate & days
        latest_day = day_change ; latest_rate = rate_change ; 
    }

    // check 




}