# include <iostream>
# include <vector> 
# include <map> 
# include <utility>
# include <algorithm> 
# include <string>
# include <set>
using namespace std ; 

int main() { 
    // for faster input
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // input data
    int count_data , count_tocheck ;
    cin >> count_data >> count_tocheck ; 
    
    set< pair<string,string> > flight_data ;  
    for (int i = 0 ; i < count_data ; i++) {
        string flight_code , flight_id ; 
        cin >> flight_code >> flight_id ; 
        
        flight_data.insert( make_pair(flight_code,flight_id) ) ; 
    }
    
    set< pair<string,string> > reserved_seat ; 
    for (int j = 0 ; j < count_tocheck ; j++) { 
        int N ; cin >> N ; 
        // define bool for checking if this bookign is available to book
        bool isAvailableToBook = true ; 
                    
        // this set will be used for added if checking flight can be booked 
        vector< pair<string,string> > to_be_reserved ; // must reset every loop check 
        
        for (int k = 0 ; k < N ; k++) { 
            string tocheck_code , tocheck_id ; 
            cin >> tocheck_code >> tocheck_id ; 

            if (!isAvailableToBook) continue;
            
            pair<string , string> flight_to_check = make_pair(tocheck_code , tocheck_id) ; 
            
            // check if data existed in set using find

            // case 1 : found , do bitwise AND as true (true & true & ... )
            if ( flight_data.find(flight_to_check) != flight_data.end() ) { 

                // need to check if that seat is in reserved or not 
                if ( reserved_seat.find(flight_to_check) == reserved_seat.end() ) {
                    isAvailableToBook &= true ; 
                    // add to temporary set of pair
                    to_be_reserved.push_back( flight_to_check ) ; 
                }
                else { 
                    isAvailableToBook &= false ; 
                }

            } 
            // case 2 : found , do bitwise AND as true (true & false & ... )
            else { 
                isAvailableToBook &= false ; 
            }
        }
           
        // after loop , check if status is true
        if (isAvailableToBook == true) {
            // print out YES and add pair to reserved
            cout << "YES" << endl ; 
            // add to_be_reserved to reserved_seat
            reserved_seat.insert( to_be_reserved.begin() , to_be_reserved.end() ) ; 
        }
        else { 
            // CAUTION : if status is FALSE , reversed seat won't be reserved
            cout << "NO" << endl ; 
        }  
    }
}
    