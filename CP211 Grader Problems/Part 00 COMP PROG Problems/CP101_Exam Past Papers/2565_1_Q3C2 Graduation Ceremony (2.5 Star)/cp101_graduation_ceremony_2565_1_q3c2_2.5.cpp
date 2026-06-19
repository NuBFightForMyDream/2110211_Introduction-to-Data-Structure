# include <iostream> 
# include <set> 
# include <vector>
# include <map>  
# include <sstream> 
# include <algorithm> 
using namespace std ; 

int main() { 
    // store data in here
    map<string , string> pundit_info ;
    map<string , set<string>> guest_info ; 
    

    // input data
    int pundit_count , guest_count , check_count ; 
    cin >> pundit_count >> guest_count >> check_count ; cin.ignore() ; 
    
    for (int i = 0 ; i < pundit_count ; i++) {
        string input_info ; getline(cin , input_info) ; 
        string pundit_name , pundit_faculty ; 
        stringstream ss(input_info); ss >> pundit_name >> pundit_faculty ; 

        pundit_info[pundit_name] = pundit_faculty ; 
    }

    for (int i = 0 ; i < guest_count ; i++) { 
        string input_info ; getline(cin , input_info) ; 
        string guest_name , pundit_to_visit ; 
        stringstream ss(input_info); 

        // get guest first 
        if (ss >> guest_name) { 
            // define key:value for map 
            guest_info[guest_name] = set<string>{}; // empty set  
        }

        while (ss >> pundit_to_visit) {
            guest_info[guest_name].insert( pundit_info[pundit_to_visit] ) ; 
        }
    }

    // check intersected faculty 
    for (int i = 0 ; i < check_count ; i++) { 
        set<string> intersected_faculty ; 

        string input_info ; getline(cin , input_info) ; 
        stringstream ss(input_info); 

        // set initial value
        if (ss >> input_info) { 
            // define key:value for map 
            intersected_faculty = guest_info[input_info] ; 
        }

        // get intersected info 
        while (ss >> input_info) {
            set<string> temp_data ; // temporary set for inserter 

            set_intersection( intersected_faculty.begin() , intersected_faculty.end() ,
                              guest_info[input_info].begin() , guest_info[input_info].end() , 
                              inserter(temp_data , temp_data.begin()) )  ; 

            intersected_faculty = temp_data ; // replace temp_data back 
        }

        // check if st isn't empty 
        if (intersected_faculty.empty() == true) cout << "None" << endl ; 
        else {
            for (auto each_faculty : intersected_faculty) cout << each_faculty << " " ; 
            cout << endl ; 
        }

    }

}