#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <functional> // greater
#include <queue> // for priority_queue
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	// your code goes here
	priority_queue< pair<long long , long long> , 
	                   vector<pair<long long , long long>> , 
	                   greater<pair<long long , long long>> 
	> chef_queue ; // {time_ready , customer}
	
	// ready time should be lowest , so we reverse priority with greater<> (default = less<>)
	
	long long count_table , count_customer ; 
	cin >> count_table >> count_customer ;
	
	// input data 
	vector<long long> table_time ;
	for (long long i = 0 ; i < count_table ; i++) {
	    long long eating_time ; cin >> eating_time ; 
	    table_time.push_back(eating_time) ; 
	}
	
    // define chef ready time 
    // logic : we need chef that is in ready state 
    
    for (long long tbid = 1 ; tbid <= count_table ; tbid++) { 
        chef_queue.push( make_pair(0 , tbid) ) ; 
    }
    
    // process each customer
    for (long long cust = 1 ; cust <= count_customer ; cust++) { 
        // get most ready chef
        auto [ready_time , table_id] = chef_queue.top() ; // pair<ll , ll>

        // display each customer then pop
        chef_queue.pop() ; 
        cout << ready_time << endl ; 
        
        // add new time to chef 
        chef_queue.push( make_pair(ready_time + table_time[table_id - 1] , table_id) ) ; 
        // note that table id start from 1 , so we need to minus -1
    }
    
    // Note : this problem shouldn't use reference in pq (bcz ref will try to point at old data)
    // it will happen "dangling reference" -> so using copy is better 
	
	
	

}
