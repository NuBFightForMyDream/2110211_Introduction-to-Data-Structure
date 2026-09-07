#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
using namespace std ; 

int main() { 
    // define input
    vector<long long> performance_score , grader_time , student_time ;
    long long count_problem , targeted_sum_score , difference_score ; 
    cin >> count_problem >> targeted_sum_score >> difference_score ; 

    for (int i = 0 ; i < count_problem ; i++) {
        int time ; cin >> time ; 
        grader_time.push_back(time) ; 
    }
    
    for (int i = 0 ; i < count_problem ; i++) {
        int time ; cin >> time ; 
        student_time.push_back(time) ; 
    }
    
    // calculate performance_score
    for (int i = 0 ; i < count_problem ; i++) { 
        performance_score.push_back( grader_time[i] - student_time[i] ) ; 
    }

    // sort vector for using lower/upper bound
    sort( performance_score.begin() , performance_score.end() ) ; 

    // try to use nested for loop (which got me 40/100)
    long long count_perfect_score = 0 ; 
    for (int i = 0 ; i < performance_score.size() ; i++) { 
        for (int j = i + 1 ; j < performance_score.size() ; j++) {
            if ( performance_score[i] + performance_score[j] >= targeted_sum_score && \
                 performance_score[j] - performance_score[i] <= difference_score) {
                    count_perfect_score++ ; 
                }
        }
    }

    cout << count_perfect_score << endl ; 
}