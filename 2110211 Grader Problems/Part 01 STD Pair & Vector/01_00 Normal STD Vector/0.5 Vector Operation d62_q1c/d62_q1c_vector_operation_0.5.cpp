// Data 2562 Quiz 1c : Vector Operation (0.5 Star)
# include <iostream>
# include <vector> 
# include <string> // command
# include <algorithm> // sort asc/desc
# include <functional> // greater
using namespace std ; 

int main() {
    // input operator
    int number_op ; cin >> number_op ; 
    vector <int> my_vector ; // vacant vector

    // for loop input operator
    string vec_command ; 
    for (int i = 0 ; i < number_op ; i++) {
        // input command 
        cin >> vec_command ; 

        // check type
        if (vec_command == "pb") { // push back 
            // input value then append to last element 
            int value ; 
            cin >> value ; 
            my_vector.push_back(value) ; // push back with value (erase with iterator)
        }

        else if (vec_command == "sa") { // sort ascending
            // sort ascending 
            sort( my_vector.begin() , my_vector.end() ) ; // sort start with iterator begin and iterator end 
        }

        else if (vec_command == "sd") { // sort descending
            // sort ascending 
            sort( my_vector.begin() , my_vector.end() , greater<int>() ) ; // sort start with iterator begin and iterator end then sort with greatest value
        }

        else if (vec_command == "r") { // reverse element 
            // reverse element
            reverse( my_vector.begin() , my_vector.end() ) ; 
        }

        else if (vec_command == "d") { // delete element 
            // input position to delete
            int pos_to_delete ; cin >> pos_to_delete ; 
            auto iter_del = my_vector.begin() + pos_to_delete ; 

            // delete element with erase() 
            my_vector.erase( iter_del ) ; 
        }
    }

    // print out vector
    for (int i = 0 ; i < my_vector.size() ; i++) {
        cout << my_vector[i] << " " ; 
    }
    cout << endl ; 

}