#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
using namespace std ; 

int main() { 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

    int count_event ; cin >> count_event ; 
    map <int , map<long long,long long> > update_info ; 
    map <int , vector<int>> pos_changed_info ; // pos_to_check : version_changed --> note that version wont be duplicated 
        // key = version , value = map of value 

    int version_count = 1 ; 
    // map<long long , long long> temp_value ; // for replacing new map

    for (int i = 0 ; i < count_event ; i++) { 
        char operation ; cin >> operation ; 

        if (operation == 'U') { // update value @pos with val
            long long pos_to_update , val_to_update ; 
            cin >> pos_to_update >> val_to_update ; 
            
            // update data (update to temp too_
            update_info[version_count][pos_to_update] = val_to_update ; // just update 1 value
            pos_changed_info[pos_to_update].push_back(version_count) ; 
                // note that default value from map is 0 (not -1 , so maybe we have to check if value = 0)
            
            // dont forget to update count
            version_count++ ; 
        
        }
        else { // case 2 : ask @pos with version ver (operation = A)
            long long pos_to_check, version_to_check;
            cin >> pos_to_check >> version_to_check; 
        
            auto &all_version = pos_changed_info[pos_to_check] ; 
            auto find_itr = upper_bound(all_version.begin() , all_version.end() , version_to_check) ;
                // use upper bound for binary search , cutting half
            
            
            // case 1 : never found (at begin) , return -1
            if (find_itr == all_version.begin()) { 
                cout << "-1" << endl ; 
            }
            else { 
                find_itr-- ; // now we got nearest lower
                auto version = *find_itr-- ;             
                cout << update_info[version][pos_to_check] << endl ; // get version from upper_bound then get to find val with nested map
            }
        }

    }
    
    /*
    // print check 
    for (auto &each_update : update_info) { 
        cout << each_update.first << endl ;
            
        // each_update = pair<int , map>
        for (auto &e : each_update.second) { 
            // e = pair<int,int>
            cout << e.first << " : " << e.second << endl ;
                
        }
    }
    */

    

}