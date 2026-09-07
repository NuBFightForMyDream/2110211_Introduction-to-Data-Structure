#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std ; 

int main() { 
    // define map 
    map<long long , long long> latest_time_scan ; 
    map<long long , long long> count_detection_database ; 

    long long count_student , count_detection , update_interval ; 
    cin >> count_student >> count_detection >> update_interval ; 

    for (long long i = 1 ; i <= count_student ; i++) { 
        count_detection_database[i] = 0 ; 
    }

    // loop then access value
    for (long long i = 0 ; i < count_detection ; i++) { 
        long long student_id , time ; 
        cin >> student_id >> time ; 

        // first time detect , update data to database
        if (latest_time_scan[student_id] == 0) { 
            latest_time_scan[student_id] = time ; 
            count_detection_database[student_id] = 1 ; 
        }

        // check if time enough to update 
        if (time - latest_time_scan[student_id] > update_interval) { 
            count_detection_database[student_id] += 1; 
        }
    }

    // for loop print each student id
    for (auto &each_student_data : count_detection_database) { 
        cout << each_student_data.second << endl ; 
    }
}
