#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std; 

int main() { 
    long long count_slime ; cin >> count_slime ; 
    stack<long long> slime_tower ; 

    for (long long i = 0 ; i < count_slime ; i++) { 
        long long new_slime ; cin >> new_slime ;
        
        // check if top slime can be merged
        if (new_slime % 2 == 0) { 
            // check before push 

            // first time , push 
            if (i == 0) slime_tower.push(new_slime) ; 

            else { 
                // check top 

                // check if top can be merged and top is still even 
                while ( (!slime_tower.empty()) && (slime_tower.top() % 2 == 0) && (slime_tower.top() == new_slime) ) {
                    // top_slime will always update 

                    // guard condition
                    if (slime_tower.empty() == true) break ; 

                    slime_tower.pop() ; // pop top -> to merge

                    new_slime *= 2 ; 
                }

                // then push new slime -> push after loop 
                slime_tower.push(new_slime) ; 
            }

        } 

        else { 
            slime_tower.push(new_slime) ; 
        }

    }

    cout << slime_tower.size() << endl ; 

    while (slime_tower.empty() == false) { 
        cout << slime_tower.top() << " " ; 
        slime_tower.pop() ; 
    }
    cout << endl ; 

}