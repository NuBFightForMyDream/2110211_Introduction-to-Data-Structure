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

    for (long long i = 0 ; i < count_problem ; i++) {
        int time ; cin >> time ; 
        grader_time.push_back(time) ; 
    }
    
    for (long long i = 0 ; i < count_problem ; i++) {
        long long time ; cin >> time ; 
        student_time.push_back(time) ; 
    }
    
    // calculate performance_score
    for (long long i = 0 ; i < count_problem ; i++) { 
        performance_score.push_back( grader_time[i] - student_time[i] ) ; 
    }

    // sort vector for using lower/upper bound
    sort( performance_score.begin() , performance_score.end() ) ; 

    // Example of how "performance score" works 
    
    // perf_score = < -9 -8 ... -3 -2 -1 0 1 2 3 4 5 6 7 8>
    //                         x[i]    L             R  --> like this 

    /* Note : current_score = x[i]
    RB : current_score + ? = targeted_sum ==> ? = targeted_sum - current_score
    LB : ? - current_score = diff_score ==>   ? = current_score + diff_score
    */
 
    long long count_perfect_score = 0 ; 
    for (long long i = 0 ; i < performance_score.size() ; i++) { 

        // NOTE : We have to check next element from x[i] , not x[i]
        auto next_current_score_itr = performance_score.begin() + i + 1 ; // representing score[j]
        auto current_score_itr = performance_score.begin() + i ; // representing score[i]

        // we should start from what we're finding , not from begin
        auto sum_bound_L = lower_bound( next_current_score_itr , performance_score.end() , targeted_sum_score - *current_score_itr);
        auto diff_bound_R = upper_bound( next_current_score_itr , performance_score.end() , difference_score + *current_score_itr);

        if (sum_bound_L < diff_bound_R) { 
            count_perfect_score += (diff_bound_R - sum_bound_L) ; 
        }
        
    }
    cout << count_perfect_score << endl ; 
}