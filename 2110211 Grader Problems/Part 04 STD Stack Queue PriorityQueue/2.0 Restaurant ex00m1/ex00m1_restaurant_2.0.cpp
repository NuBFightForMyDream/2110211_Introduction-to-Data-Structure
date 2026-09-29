#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
using namespace std ; 

int main() { 
    int count_table , count_customer ; 
    cin >> count_table >> count_customer ; 

    // create vector of customer
    vector<int> time_of_waiting_in_each_seat ; 
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > waiting_queue ; 

    // input      
    for (int ids = 0 ; ids < count_customer ; ids++) { 
      // assign time to chefs
      int time ; cin >> time ; 
      time_of_waiting_in_each_seat.push_back(time) ; 

      // assign time of chef to customer 
      waiting_queue.push( make_pair(0 , ids) ) ; 
    }

    
    

    // priority_queue for each customer
    // process each customer





}