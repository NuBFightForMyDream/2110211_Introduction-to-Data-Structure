# include <iostream> 
# include <map>
# include <string>
using namespace std ; 

int main() {
    int N ; cin >> N ; 
    map <string , int> word_frequency ;

    // input then add key:val to map
    for (int i = 0 ; i < N ; i++) {
        string word ; 
        cin >> word ; 

        // add key:value to map
        word_frequency[ word ] += 1 ; 
    }

    // show output
    for (auto each_word : word_frequency) {
        if (each_word.second > 1) { // each_word.second = frequency
            cout << each_word.first << " " << each_word.second << endl ; 
        }
    }
}

