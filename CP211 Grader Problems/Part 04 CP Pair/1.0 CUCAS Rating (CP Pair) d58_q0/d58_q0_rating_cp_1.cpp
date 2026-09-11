#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <utility> 
#include <iomanip>

// don't use using namespace std ; --> will crash when using CP Pair
#include "d58_q0_rating_template.h"

// CP::map is too cooked , I'll write only for CP::pair
int main() {

    // set pricision
    std::cout << std::fixed << std::setprecision(2);

    // define storage & input
    std::map<int , CP::pair<int , int>> course_rating_info ; // course_id : <total_score , count> --> for calculating average
    std::map<std::string , CP::pair<int , int>> lecturer_rating_info ;  // lecturer_name : <total_score , count> --> for calculating average

    // input then store 
    int count_rating ; std::cin >> count_rating ; 
    for (int i = 0 ; i < count_rating ; i++) { 
        int course_code , score ; std::string lecturer_name ; 
        std::cin >> course_code >> lecturer_name >> score ; 

        // store to map
        
        // update course_info
        course_rating_info[course_code].first += score ; 
        course_rating_info[course_code].second += 1 ; 

        lecturer_rating_info[lecturer_name].first += score ;
        lecturer_rating_info[lecturer_name].second += 1 ; 
    }

    // loop print output 
    for (auto &each_pair : course_rating_info) { 
        int cid = each_pair.first ; 
        CP::pair<int , int> pair_info = each_pair.second ; 

        double avg_score = (pair_info.first + 0.0) / pair_info.second ; // total_score / count
        std::cout << cid << " " << avg_score << std::endl ; 
    }

    for (auto &each_pair : lecturer_rating_info) { 
        std::string lec_name = each_pair.first ; 
        CP::pair<int , int> pair_info = each_pair.second ; 

        double avg_score = (pair_info.first + 0.0) / pair_info.second ; // total_score / count
        std::cout << lec_name << " " << avg_score << std::endl ; 
    }
}