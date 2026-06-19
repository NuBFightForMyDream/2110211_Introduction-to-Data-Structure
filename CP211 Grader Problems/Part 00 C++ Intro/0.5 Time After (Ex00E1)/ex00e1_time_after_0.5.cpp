// Time After : exe001 (0.5 Star)

# include <iostream> 
# include <cmath>
# include <string> 
# include <iomanip> // io manipulation for setfill zeros
using namespace std ; 

int main() {
    // 1 input : define variables
    int hour , min ; 
    cin >> hour >> min ; 

    int min_passed ;
    cin >> min_passed ;

    // 2.1 process : calculate to minute
    int total_min = 60 * hour + min ; 
    int total_min_after = total_min + min_passed ; 

    // 2.2 process : calculate to after hour & min
    int hour_after = ( total_min_after / 60 ) % 24 ; // mod in case >24h
    int min_after = total_min_after % 60 ; // only care minutes 

    // 3 output -> check minute if < 10 -> format to 00
    cout << setfill('0') << setw(2) << hour_after << " "
         << setfill('0') << setw(2) << min_after << endl; // set width to 2 , set fill with 0
}