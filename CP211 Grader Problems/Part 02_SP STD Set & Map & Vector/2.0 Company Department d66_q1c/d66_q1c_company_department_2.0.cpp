#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility> // pair
#include <string>
using namespace std ; 

int main() { 
    int count_employee , count_event ; 
    cin >> count_employee >> count_event ; 

    map<string , set<string> > company_info ; // not that set can erase value directly 
    map<string , string> employee_info ; // for finding value in map

    for (int i = 0 ; i < count_employee ; i++) { 
        string employee_name , dept_name ; 
        cin >> employee_name >> dept_name ; 
        company_info[dept_name].insert( employee_name ) ;
        employee_info[employee_name] = dept_name ; 
    }

    // check event 
    for (int i = 0 ; i < count_event ; i++) { 
        int type ; cin >> type ; 

        // check type 
        if (type == 1) { // change department
            string name_to_change , dept_to_change ;    
            cin >> name_to_change >> dept_to_change ; 

            // check that employee isn't in same department 
            if (employee_info[name_to_change] != dept_to_change) { 
                // erase from old department then add employee to new department
                string dept_to_delete = employee_info[name_to_change] ; 

                company_info[dept_to_delete].erase(name_to_change) ; // erase
                company_info[dept_to_change].insert(name_to_change) ; // add 


                // update data to employee_info
                employee_info[name_to_change] = dept_to_change ; 
            } 
        }

        else if (type == 2) { // merge department 

            string dept_to_destroy , dept_to_merge ;
            cin >> dept_to_destroy >> dept_to_merge ; 

            // dont erase itself department
            if (dept_to_destroy == dept_to_merge) continue; 

            // for loop change employee_info (which is not affect to company_info)
            for (auto &each_name : company_info[dept_to_destroy]) { 
                employee_info[each_name] = dept_to_merge ; 
            }

            // insert all element in dept_to_destroy into dept_to_merge
            auto set_to_destroy = company_info[dept_to_destroy] ; // set<string>
            auto set_to_merge = company_info[dept_to_merge] ; // set<string>
            
            set_to_merge.insert(set_to_destroy.begin() , set_to_destroy.end()) ; 
            company_info[dept_to_merge] = set_to_merge ; 

            // erase key (dept_name) in company_info
            company_info.erase(dept_to_destroy) ;  
        }
    }

    // output 
    for (auto &each_dept_name : company_info) { // pair -> get key 
        cout << each_dept_name.first << ": " ; 

        for (auto &each_employee_name : company_info[each_dept_name.first]) { 
            cout << each_employee_name << " " ; 
        }
        cout << endl ; 
    } 

}