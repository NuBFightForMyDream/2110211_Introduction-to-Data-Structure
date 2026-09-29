#include <iostream> 
#include <vector> 
#include <set>
#include <algorithm> 
using namespace std;

int main() {
	// input data 
	int count_store_size , count_customer_size ; 
	cin >> count_store_size >> count_customer_size ; 
	
	vector<int> store_size ; 
	for (int i = 0 ; i < count_store_size ; i++) { 
	    int each_store_size ; cin >> each_store_size ; 
	    store_size.push_back(each_store_size);
	}
	sort(store_size.begin() , store_size.end());
	
	for (int j = 0 ; j < count_customer_size ; j++) {
	    int each_customer_size ; cin >> each_customer_size ; 
	    
	    // use lower bound to get possible size 
	    // why : because we need >= value , but upper will cover > only
	    
	    auto best_fit_size_itr = lower_bound(store_size.begin(), store_size.end(), each_customer_size); 
	    
	    // case 1 : smallest size possible 
	    if (best_fit_size_itr == store_size.begin()) { // customer < smallest_store 
	        cout << *best_fit_size_itr << " " ; 
	    }
	    
	    // case 2 : biggest size possible
	    else if (best_fit_size_itr == store_size.end()) { // customer > biggest_store 
	        cout << *(best_fit_size_itr - 1) << " " ; // note : end dont have value , so step back
	    }
	    
	    // case 3 : general case , check distancee of best fit (left & right)
	    else { 
	        // if having >= 2 beest size (i.e. 60 (store) < 90 (customer) < 120 (store) , giving bigger size)
	        //  auto bigger_best_fit_size = lower_bound(store_size.begin(), store_size.end(), each_customer_size) ; // lowerb will always give bigger value ==> use best_fit_size instead
	        auto smaller_best_fit_itr = best_fit_size_itr - 1 ; 
	       
	        // check size : 3 case 
	        
	        // case 3.1 : smaller is more best fit than bigger , return smaller
	        if (llabs(each_customer_size - *smaller_best_fit_itr) < llabs(each_customer_size - *best_fit_size_itr) ) {
	            cout << *smaller_best_fit_itr << " " ; 
	        }
	        else if (llabs(each_customer_size - *smaller_best_fit_itr) > llabs(each_customer_size - *best_fit_size_itr)){
	            cout << *best_fit_size_itr << " " ; 
	        } 
	        else { // equal size , giving bigger size
	            cout << *best_fit_size_itr << " " ; 
	        }
	        
	    }
	    
	    
	}
	

}
