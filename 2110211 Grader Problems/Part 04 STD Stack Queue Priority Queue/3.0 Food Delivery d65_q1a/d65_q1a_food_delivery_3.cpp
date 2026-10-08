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
    map<long long , long long> cumulative_order_info = {{0,0}} ; // {sales , order_count}
    long long order_done = 1 , cumulative_sales = 0 ; // initial value 

    // input
    for (long long i = 0 ; i < count_target ; i++) { 
        long long target_val ; cin >> target_val ; 
        target_info.push_back(target_val) ;
    }

    for (long long i = 0 ; i < count_event ; i++) { 
        long long operation ; cin >> operation ; 

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

            long long order_to_pick_value ; 

            // NOTE : CAN COOK ONLY 1 TIME PER ORDER

            // case 1 : have 2 orders
            if ( (foodplathong_order.empty() == false) && (dotman_order.empty() == false) ) { 
                long long check_foodplathong = foodplathong_order.front() ; 
                long long check_dotman = dotman_order.front() ; 
                
                if (check_dotman < check_foodplathong) { // lower price win 
                    order_to_pick_value = check_dotman ; 
                    dotman_order.pop() ; 
                }     
                else { // same price and (dotman > foodplathong)
                    order_to_pick_value = check_foodplathong ; 
                    foodplathong_order.pop() ; 
                }
            }   

            // case 2 : have 1 orders , pick that order
            else if ( (foodplathong_order.empty() == false) && (dotman_order.empty() == true) ) { // foodplathong have order
                order_to_pick_value = foodplathong_order.front() ; 
                foodplathong_order.pop() ; 
            }
            else if ( (foodplathong_order.empty() == true) && (dotman_order.empty() == false) ) { // dotman have order
                order_to_pick_value = dotman_order.front() ; 
                dotman_order.pop() ; 
            }

            // for all case : sum total_order to cumulative_sales
            cumulative_sales += order_to_pick_value ; 

            long long total_sales_each_day = cumulative_sales ; // {sales , order_count}

            cumulative_order_info[total_sales_each_day] = order_done ; 
            order_done++ ; // dont forget to add order
            

        }
    } // end for loop of doing order
    
    /*
        // check print 
        for (auto a : cumulative_order_info) {
            cout << a.first << " " << a.second << endl ; 
        }
    */

    // now use upper_bound / lower_bound for checking cumulative_order_info 
    for (long long j = 0 ; j < target_info.size() ; j++) { 
        // use lower_bound because >= sales
        auto it = cumulative_order_info.lower_bound(target_info[j]) ; // {sales , order_count}
            // use map.lower_bound() instead of lower_bound(...) algorithm

        // check if not found 
        if (it == cumulative_order_info.end()) { 
            cout << -1 << " " ; // store closed
        } 
        else {
            cout << it->second << " " ; 
        }
    }
    cout << endl ; 
}