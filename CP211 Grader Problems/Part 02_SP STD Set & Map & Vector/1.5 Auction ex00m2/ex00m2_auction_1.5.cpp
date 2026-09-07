#include <iostream>
#include <algorithm> 
#include <map> 
#include <utility> // pair 
#include <vector> 
#include <string> 
using namespace std;

int main() {
    // ----------------- PART 1 : Input Data -----------------
	// input data of bidding 
	int count_item_type , count_bidder , count_actions ; 
	cin >> count_item_type >> count_bidder >> count_actions ; 
	
	// store data in map 
    map<int , int> inventory ; 
        // this represents how many pieces left for each item type : <type_num : piece_left>
    map<int , map<int , int> > item_bidding_info ;
        // this represent info of bidding on each item : <type : < 80:p1 , 90:p2 , ... > >
    map<int , vector<int> > result_bidder_info ; 
        // this represent each player's win of bidding each item : <bidder1 : <item1> , bidder2 : <> >   
    
    // initialize data in inventory , item_bidding_info , bidder_info respectively
	for (int item_num = 1 ; item_num <= count_item_type ; item_num++) { 
	    int count_item_type ; cin >> count_item_type ; 
	    inventory[ item_num ] = count_item_type ;
	}
	
	for (int item_num = 1 ; item_num <= count_item_type ; item_num++) { 
        item_bidding_info[ item_num ] = map<int , int>() ; 
	}
	
	for (int bidder_num = 1 ; bidder_num <= count_bidder ; bidder_num++) { 
	    result_bidder_info[ bidder_num ] = vector<int>() ; 
	}

    // ----------------- PART 2 : Input Bidder Data for bidding algorithm -----------------
    for (int i = 0 ; i < count_actions ; i++) { 
        // input data
        char action ; int user_num , item_num , value ; 
        cin >> action ; 
        
        if (action == 'B') { 
            // input user_num , item_num , value
            cin >> user_num >> item_num >> value ; 
            // input data to item_bidding_info
            item_bidding_info[ item_num ][ user_num ] = value ; // change to vector to sort later 
        }
        
        else if (action == 'W') { // withdrawn from bidding
            cin >> user_num >> item_num ; 
            
            // delete data from bidding 
            item_bidding_info[ item_num ].erase( user_num ) ;
        }
        
    }

    // PART 3 : sort item_bidding_info then doing bidding algorithm
    
    
    
    
}
