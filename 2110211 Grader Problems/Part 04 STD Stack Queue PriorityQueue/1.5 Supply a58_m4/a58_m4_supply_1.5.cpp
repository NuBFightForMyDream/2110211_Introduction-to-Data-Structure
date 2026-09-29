#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <utility> // pair
#include <queue> // having priority queue inside 
using namespace std ; 

int main() { 
    int count_plant , count_storage , count_days ; 
    cin >> count_plant >> count_storage >> count_days ; 

    // create priority queue for storing plant & queue 

    // note : plant --> stock in plant or wait for product 
           // store --> request product (from plant) or wait 

    // maybe store with "priority queue" ? with (day , store_num) / (day , plant_num) 
    priority_queue< pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>> > waiting_queue_from_store ; // wait for store to request 
    priority_queue< pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>> > stocking_queue_from_plant ; // wait for plant to produce
    // writing greater<int> to reverse order (day with less value will come first)
    
    map< int , pair<int,int> > operations_input ; // ( day , {event , number} )
    map< int , int > operations_output ; // ( day , output_label )
    
    // writing greater<int> to reverse order (day with less value will come first)

    // input data
    for (int i = 0 ; i < count_days ; i++) {
        int day , event , number_plant_or_store ; 
        cin >> day >> event >> number_plant_or_store ; 

        operations_input[day] = make_pair(event , number_plant_or_store) ; // days will be unique 
    }

    // Logic : Check type of event input 
        // Type 0 (A) --> produce then sent product to store 
        // Type 1 (B) --> request then get product or wait (if no stock left)

    
    // loop check operations each day 
    for (auto& [current_day , data_pair] : operations_input) { 
        // define variable 
        int event_type = data_pair.first , label = data_pair.second ; 

        if (event_type == 0) { // event A : produce
            // Steps 
              // 1. produce -> Check if waiting queue is available 
              // 2. If waiting queue is not empty -> sent item to requested
              // 3. Else if waiting queue is empty -> sent to stock then return 0

            if (waiting_queue_from_store.empty() == false) { // send
                operations_output[current_day] = waiting_queue_from_store.top().second ; 
                waiting_queue_from_store.pop() ; 
            }
            else { // stock value then print 0 as nothing to sent
                stocking_queue_from_plant.push( make_pair(current_day , label) ) ; // produce 
                operations_output[current_day] = 0 ; 
            }
        }

        else if (event_type == 1) { // event B : request
            // Steps 
              // 1. request -> Check if stocking queue is available 
              // 2. If stocking queue is not empty -> sent item from stocking to output
              // 3. Else if stocking queue is empty -> add to waiting queue
      
            // check request then get product or wait
            if (stocking_queue_from_plant.empty() == false) { 
                operations_output[current_day] = stocking_queue_from_plant.top().second ; 
                stocking_queue_from_plant.pop() ; 
            }
            else { 
                // add to waiting queue then print 0 out 
                waiting_queue_from_store.push( make_pair(current_day , label) ) ; // wait
                operations_output[current_day] = 0 ; 
            }
        }
    }

    // output by day 
    for (auto& [day_out , output_label] : operations_output) { 
        cout << output_label << "\n" ; 
    }


}