# include <iostream> 
# include <algorithm> 
# include <queue>
# define base 10 // base variable will be 10 for this file 
using namespace std ;

// define getDigit function
int getDigit(int val , int dig_k) {
    // return value of k_th digit of val
    int i ;
    for (i = 0 ; i < dig_k ; i++) { 
        val /= base ;
    }
    return val % base ; 
    // Ex : getDigit(539 , 2) = 3
}

// define radix sort function 
void radixSort(vector<int> &data , int d) { 
    // define queue 0 - base (represent storage for each digit)
    queue<int> digit_storage[base] ;
    
    // loop digit from 0 to d
    for (int k = 0 ; k < d ; k++) {
        // push data to each digit first 
        for (auto &x : data) { // x = each value  
            digit_storage[ getDigit(x,k) ].push(x) ; 
        } 

        // get data from digit_storage then put back to original data , then clear out queue
        for (int dig = 0 , pos = 0 ; dig < base ; dig++) { 
            while (! digit_storage[dig].empty()) { 
                data[pos++] = digit_storage[dig].front(); // front-est out first 
                digit_storage[dig].pop() ; // pop data out 
            }
        }
    } 
}

int main() { 
    vector<int> data = {115 , 42 , 52 , 9 , 453 , 876 , 747 , 845 , 652 , 45, 75, 90, 802, 24, 2, 66};
    int max_digit = 3 ;  

    // do radix sort algorithm
    radixSort(data , max_digit);

    // get sorted data
    cout << "Sorted Data from Radix Sort : " << endl ; 
    for (auto &c : data) cout << c << " " ; 

    return 0 ;
}