// Part 00 : C++ Intro 
// a60b_mid_p2 Rope (1 Star) 

# include <iostream> 
# include <string>
# include <algorithm> 
using namespace std ; 

// Note : This problem is "Dynamic Programming"
// But no need to use in this problem

// double loop a,b for checking remainder
// from equation of rope : len1 * count1 + len2 * count2 + len3 * count3 = total_length 

int main() { 
    int total_length , len_a , len_b , len_c , total_count = 0 ; 
    cin >> total_length >> len_a >> len_b >> len_c ; 

    // we need "MOST POSSIBLE COUNT" for rope cutting 
    for (int count_a = 0 ; count_a <= total_length / len_a ; count_a++) { // round_a = total_a / len_a
        for (int count_b = 0 ; count_b <= total_length / len_b ; count_b++) { 
            
            // calculate remainder
            int length_remain = total_length - (count_a * len_a) - (count_b * len_b) ; 

            // check if length c can be cut 
            if (length_remain < 0) continue ; // ignore this case , going next loop

            if (length_remain % len_c == 0) { 
                // check count_c
                int count_c = length_remain / len_c ; 

                // check if cuttable (total_count > 0)
                if (count_a + count_b + count_c > total_count) { 
                    total_count = count_a + count_b + count_c ; 
                }
            }
        }
    }

    cout << total_count << endl ; 
}