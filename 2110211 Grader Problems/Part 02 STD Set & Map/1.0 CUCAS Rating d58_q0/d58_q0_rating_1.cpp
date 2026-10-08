# include <iostream> 
# include <map> 
# include <string>
# include <utility> 
# include <iomanip>
using namespace std ; 

int main() {
    // create map 
    map <string , pair<long long , int> > course_code_info ; // map automatically sort with alphabet
    map <string , pair<long long , int> > lecturer_info ; // map automatically sort with alphabet

    // input info 
    int N ; cin >> N ; 
    for (int i = 0 ; i < N ; i++) {
        string course_code , lecturer ; 
        int score ; 
        cin >> course_code >> lecturer >> score ; 

        // update course_code_info and lecturer_info 
        course_code_info[ course_code ].first += score ; // update score
        course_code_info[ course_code ].second += 1 ; // update frequency

        lecturer_info[ lecturer ].first += score ; // update score
        lecturer_info[ lecturer ].second += 1 ; // update frequency

    }

    // setprecision 2 decimal pts
    cout << fixed << setprecision(2) ; 

    // calculate average then display
    for (auto & score_info : course_code_info) { // & for not copying
        // info = <string , pair<ll , int> >
        
        long long score = (score_info.second).first ; // (.second for value in map)
        int count = (score_info.second).second ; 
        string course_code = score_info.first ; 

        // display score
        cout << course_code << " " << (score + 0.0) / count << endl ; 
    }
    
    for (auto &lec_info : lecturer_info) { // & for not copying
        // info = <string , pair<ll , int> >
        long long score = (lec_info.second).first ; // (.second for value in map)
        int count = (lec_info.second).second ; 
        string lecturer_name = lec_info.first ; 

        // display score
        cout << lecturer_name << " " << (score + 0.0) / count << endl ; 
    }

}