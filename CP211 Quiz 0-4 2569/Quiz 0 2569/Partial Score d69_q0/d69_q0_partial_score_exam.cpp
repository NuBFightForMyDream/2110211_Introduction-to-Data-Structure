#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
using namespace std ; 

int main() { 

    vector<long long> database_grader_time , database_student_done_time ; 
    vector<long long> performance_score ; 

    long long count_pair , targeted_perf_score , max_diff_perf_score ; 
    cin >> count_pair >> targeted_perf_score >> max_diff_perf_score ; 

    for (int i = 0 ; i < count_pair ; i++) {
        long long grader_reference_time ; cin >> grader_reference_time ; 
        database_grader_time.push_back(grader_reference_time) ; 
    }

    for (int i = 0 ; i < count_pair ; i++) { 
        long long student_done_time ; cin >> student_done_time ; 
        database_student_done_time.push_back(student_done_time) ; 
    }

    // check performance score
    for (long long i = 0 ; i < count_pair ; i++) { 
        performance_score.push_back( database_grader_time[i] - database_student_done_time[i] );
    }

    // sort score first 
    sort( performance_score.begin() , performance_score.end() ) ; 

    // use 2 iterator to sum all possible values
    long long left = 0 , right = count_pair - 1 ;
    long long count_perfect_score ; 


    while (left < right) { 
        // find lb itr that has difference first
        if (performance_score[right] - performance_score[left] > max_diff_perf_score) { 
            left++ ; 
        }
        if (performance_score[left] + performance_score[right] < targeted_perf_score) {
            right-- ;
        } 

        else { 
            auto count_total = right - left + 1;
            count_perfect_score += count_total ; 
            left++ ;  
        }
    } 

    cout << count_perfect_score << endl ; 
}