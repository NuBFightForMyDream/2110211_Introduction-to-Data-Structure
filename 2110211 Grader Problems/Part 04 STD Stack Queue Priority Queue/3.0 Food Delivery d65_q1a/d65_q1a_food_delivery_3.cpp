#include <iostream>
#include <queue> // queue & priority_queue
#include <functional> // greater
#include <vector>
#include <set>
#include <map>
using namespace std ; 

int main() { 
    long long count_event , count_target ; 
    cin >> count_event >> count_target ; 

    vector<long long> target_info ; // collecting target

    // this represent how order come in on each restaurant
    queue<long long> foodplathong_order ; 
    queue<long long> dotman_order ; 

    // this is defined for using lower_bound to check order to cook
    map<long long , long long> cumulative_sales ; // {order_count , sales}
    long long order_done = 0 ; 

    // input
    for (long long i = 0 ; i < count_target ; i++) { 
        long long target_val ; cin >> target_val ; 
    }

    for (long long i = 0 ; i < count_event ; i++) { 
        long long operation ; 

        if (operation == 1) { // order come in 
            long long store_id , sales ; 
            cin >> store_id >> sales ; 

            if (store_id == 1) { // foodplathong
                foodplathong_order.push( sales ) ; 
            }
            else if (store_id == 2) { // dotman
                dotman_order.push( sales ) ;  
            }
        }

        else if (operation == 2) { // cook food
            // check condition of picking order to cook
            
            // check which price is lower from two apps 
            // if order only from 1 store , pick that order
            // else if order have same price , pick foodplathong

            // case 1 : have 2 orders
            if ( (foodplathong_order.empty() == false) && (dotman_order.empty() == false) ) { 

            }
        }
    }
}