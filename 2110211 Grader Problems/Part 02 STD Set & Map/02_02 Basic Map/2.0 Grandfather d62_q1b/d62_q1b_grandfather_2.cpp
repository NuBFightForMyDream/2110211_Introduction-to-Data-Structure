# include <iostream> 
# include <vector> 
# include <map>
# include <algorithm> 
using namespace std ; 

// function for find parents and grandparents
long long find_parents(map<long long ,long long> &offspring_to_parent , long long offspring_id) { 
    // case 1 : not found in database , return -1 (not found)
    if ( offspring_to_parent.find(offspring_id) == offspring_to_parent.end() ) return -1 ; 

    // general case : find in map then return id of parents
    else return offspring_to_parent[offspring_id] ; 
}

int find_grandparents(map<long long ,long long > &offspring_to_parent , long long offspring_id) { 
    // case 1 : parent doesnt exist , grandparents wont exist too 
    if (find_parents(offspring_to_parent , offspring_id) == -1) return -1 ; 

    else { 
        long long parent_id = find_parents(offspring_to_parent , offspring_id) ; // parent exist 
        // case 2 : parent exist , grandparent doesnt exist 
        if ( find_parents(offspring_to_parent , parent_id) == -1 ) return -1 ;  

        // general case : find grandparent from parent 
        else return offspring_to_parent[parent_id] ; 
    }
}

int main() { 
    long long count_relations , count_check ; 
    cin >> count_relations >> count_check ; 

    // input relation into map 
    map<long long , long long> offspring_to_parent ; 

    // input relations

    for (long long  i = 0 ; i < count_relations ; i++) { 
        long long parent_id , offspring_id ; 
        cin >> parent_id >> offspring_id ; 

        // input data into map 
        offspring_to_parent[offspring_id] = parent_id ; 
    }

    // input check algorithm
    for (long long j = 0 ; j < count_check ; j++) { 
        long long check_id1 , check_id2 ;
        cin >> check_id1 >> check_id2 ; 

        // -- filter some case out --

        // case 1 : self check , return NO
        if (check_id1 == check_id2) cout << "NO" << endl; 

        else { 
            // define parent & grandparent id to check
            long long parent_of_id1 = find_parents(offspring_to_parent , check_id1);
            long long parent_of_id2 = find_parents(offspring_to_parent , check_id2);

            long long grandparent_of_id1 = find_grandparents(offspring_to_parent , check_id1); 
            long long grandparent_of_id2 = find_grandparents(offspring_to_parent , check_id2);

            // case 2 : check if grandparent exist 
            if ((grandparent_of_id1 == -1)|| (grandparent_of_id2 == -1)) cout << "NO" << endl ; 
            
            // general case
            else { 
                if (grandparent_of_id1 == grandparent_of_id2) cout << "YES" << endl; 
                else cout << "NO" << endl; 
            }
        }
    }
}