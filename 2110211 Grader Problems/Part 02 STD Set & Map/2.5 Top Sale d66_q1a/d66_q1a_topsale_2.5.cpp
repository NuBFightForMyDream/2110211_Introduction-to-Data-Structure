#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
using namespace std ; 

int main() { 
    std::ios_base::sync_with_stdio(false); std::cin.tie(0) ; 

    int count_product , count_event ; 
    cin >> count_product >> count_event ; 

    set<int> somchai_label_list , other_label_list ; 
    map<int , int> somchai_map ; // {quantity , label} --> for updating value (CANT USE MAP FOR SORTING SALES INFO)
    set< pair<int , int> > somchai_sales_info ; // {quantity , label} --> for finding data
        // note that set<pair> sort ascending , we need to find < K piece but most id , so we need to move iterator

    for (int j = 0 ; j < count_product ; j++) {
        int num ; cin >> num ; 
        somchai_label_list.insert(num) ; 
    }

    for (int i = 0 ; i < count_event ; i++) { 
        int event_type ; cin >> event_type ; 

        if (event_type == 1) { // sale
            int label , quantity ; 
            cin >> label >> quantity ; 

            // check if product belongs to somchai 
            auto it_find = somchai_label_list.lower_bound(label);
            if ( (it_find != somchai_label_list.end()) && (*(it_find) == label) ) { // belongs to somchai

                // calculate old_quantity and new_quantity
                int old_quantity = somchai_map[label] ;
                int new_quantity = old_quantity + quantity ; 

                // erase old {quantity , label}
                somchai_sales_info.erase({old_quantity , label}) ; // set can use erase value , not like vector

                // add value to map [label : quantity]
                somchai_map[label] += quantity ;   

                // add new {quantity , label} to map 
                somchai_sales_info.insert({new_quantity , label}) ; // set can use erase value , not like vector

            }

            // set will looks like : { {3,2} , {4,1} , {5,3} , {10,4} , {10,7} } --> {quantity , label}

            else { // not belongs to somchai
                // add to other_label_list 
                other_label_list.insert(label) ; 
            }

        } 
        else if (event_type == 2) { // ask 
            int targeted_quantity_k ; cin >> targeted_quantity_k ; // K is value needed for checking if data is in topsale

            // use set.lower_bound() to check iterator instead of find() 
            auto most_sale_in_condition_itr = somchai_sales_info.lower_bound({targeted_quantity_k , 0}) ; 
                // we need lowest_label first , then move itr until find most id that wont change k  

            // check for most id with same targeted_k

            // edge case : if no products sales less than k , return NONE
            if ( most_sale_in_condition_itr == somchai_sales_info.begin() ) { // NOTE THAT WE NEED LABEL THAT HAVE SALES < K (SO ITS IMPOSSIBLE TO BE AT BEGIN)
                cout << "NONE" << "\n" ; 
            }

            else { 
                --most_sale_in_condition_itr ; // backward 1 step then we get order 
                cout << most_sale_in_condition_itr->second << endl ;  
            }

        }
    }
}