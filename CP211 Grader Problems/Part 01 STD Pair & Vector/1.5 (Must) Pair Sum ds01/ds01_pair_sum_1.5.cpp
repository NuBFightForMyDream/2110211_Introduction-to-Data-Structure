#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool pairSumAlgorithm(vector<int> &nums , int checkNumber) {
    // define left & right iterator to move 
    int left_pos = 0 , right_pos = nums.size() - 1 ; 
    bool foundPairSum = false ; 
    
    sort(nums.begin() , nums.end()) ; 
    
    while (left_pos < right_pos) { 
        if (nums[left_pos] + nums[right_pos] == checkNumber) { 
            foundPairSum = true ; 
            return true ;
        }
        else { 
            if (nums[left_pos] + nums[right_pos] > checkNumber) { // ถ้าน้อยกว่าค่าที่ต้องการหา --> ไม่เจอเเน่ๆ ต้องขยับขวาเข้ามา
                right_pos--;
            }
            
            else { // ถ้าน้อยกว่าค่าที่ต้องการหา --> ไม่เจอเเน่ๆ ต้องขยับซ้ายเข้ามา
                left_pos++;
            }
            
        }
        
    }
    
    if (foundPairSum == false) { 
        return false ;
    }
    
    /*
    for (int i = 0 ; i < nums.size() ; i++) { 
        for (int j = i ; j < nums.size() ; i++) {
            if (nums[i] + nums[j] == checkNumber) return true ;     
        }
    }
    // cant find , return false 
    return false ;
    */
    
}

int main() {
	// your code goes here
	int sizeArray ; cin >> sizeArray ; 
	vector<int> numbers ; 
	int countCheckNumber ; cin >> countCheckNumber ; 
	
	// Step 1 : input array 
	for (int pos = 0 ; pos < sizeArray ; pos++) { 
	    int num ; cin >> num ; 
	    numbers.push_back(num) ;
	}
	
	// Step 2 : Loop check number
	for (int i = 0 ; i < countCheckNumber ; i++) {
	    int checkNumber ; cin >> checkNumber ; 
	    // call pairSumAlgorithm function to check if number can do pair sum 
	    if (pairSumAlgorithm(numbers , checkNumber) == true) {
	        cout << "YES" << endl;
	    }
	    else { 
	        cout << "NO" << endl ; 
	    }
	}
}
