# include <iostream> 
# include <vector> 
# include <set> 
# include <string>
# include <map>
# include <algorithm>
using namespace std ; 

string encoding_password_algorithm(string check_password , vector<int> pos_to_encode_vector) { 
    // define string with double alphabet pattern
    string alphabets = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz" ; 
    string encoded = "" ; 

    // loop for encoding
    for (int i = 0 ; i < pos_to_encode_vector.size() ; i++) { 
        // find current position of letter 
        int pos_found = alphabets.find( check_password[i] ) ; 
        int pos_encoded = pos_found + pos_to_encode_vector[i] ; 
        encoded += alphabets[pos_encoded] ; 
    }

    // return encoded string
    return encoded ;
}

int main() { 
    // 1 : input data 
    int count_database_password , count_check_password , encoding_length ; 
    cin >> count_database_password >> count_check_password >> encoding_length ;

    vector<int> pos_to_encode_vector ; 
    for (int i = 0 ; i < encoding_length ; i++) { 
        int encoding_number ; cin >> encoding_number ; 
        encoding_number %= 26 ; // must mod by 26 
        // add to vector
        pos_to_encode_vector.push_back(encoding_number) ; 
    }

    set<string> database_password ; 
    for (int i = 0 ; i < count_database_password ; i++) { 
        string password ; cin >> password ; 
        database_password.insert(password) ; 
    }

    // 2 : check encoding password if its same as in database (main algorithm)
    for (int j = 0 ; j < count_check_password ; j++) { 
        string check_password ; cin >> check_password ; 

        string encoded_password = encoding_password_algorithm(check_password , pos_to_encode_vector) ; 
        // check if encoded password in database
        if ( database_password.find(encoded_password) != database_password.end() ) { // found
            cout << "Match" << "\n" ; 
        }
        else { 
            cout << "Unknown" << "\n" ; 
        }
    }

}