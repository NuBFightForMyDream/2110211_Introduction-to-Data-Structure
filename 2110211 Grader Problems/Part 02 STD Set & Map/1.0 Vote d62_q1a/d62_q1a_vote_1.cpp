# include <iostream>
# include <algorithm> 
# include <vector> 
# include <map>
# include <utility> // pair 
using namespace std;

int main() {
	// input data in map form : { {chatrphol , 1} , ... }
	map<string , int> vote_result ; 
	
    int count_candidate ; cin >> count_candidate ; 
    int count_required_candidate ; cin >> count_required_candidate ; 
    
	for (int i = 0 ; i < count_candidate ; i++) { 
	   string candidate ; cin >> candidate ; 
	   vote_result[candidate]++ ; // map will add key:value automatically if not found and will sort automatically 
	}
	
	// build new vector sorted with vote_count then sort with alphabetically
	vector< pair<int,string> > ranked_vote_result ; 
	for (auto each_data : vote_result) { // each_data = pair<string,int> 
	    ranked_vote_result.push_back( {-each_data.second , each_data.first} ) ; 
	}
	
	sort(ranked_vote_result.begin() , ranked_vote_result.end()) ; 
	
	// check numbers of candididate that pass requirement
	int total_count_candidate = ranked_vote_result.size() ; 
	
	// check condition of pass candididate
	if (total_count_candidate <= count_required_candidate) { 
	    // get least vote count
	    auto least_vote_itr = ranked_vote_result.end() ; least_vote_itr-- ; 
	    cout << -(*least_vote_itr).first << endl ; // least vote count
	}
	
	else {
	    // get last element in bound of count_required_candidate 
	    auto least_vote_itr = ranked_vote_result.begin() + count_required_candidate - 1 ; // v.begin() = first element
	    cout << -(*least_vote_itr).first << endl ; // least vote count
	}
	
	

}
