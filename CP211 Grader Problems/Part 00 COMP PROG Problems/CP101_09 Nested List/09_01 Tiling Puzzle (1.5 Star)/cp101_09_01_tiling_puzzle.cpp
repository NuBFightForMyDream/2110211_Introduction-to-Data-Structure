# include <iostream> 
# include <string> 
# include <utility> // pair 
# include <algorithm>
using namespace std ; 

int row_number(vector<vector<int>> tile , int element) { 
    // return pair of row and column number of t containing e (top row is row #0)
    // guarante that element will be existed in tile
    for (int r = 0 ; r < tile.size() ; r++) { 
        for (int c = 0 ; c < tile[0].size() ; c++) { 
            if (tile[r][c] == element) return r ; 
        }
    }
}

vector<int> flatten_tile( vector<vector<int>> tile ) { 
    // return a vector of int converted from vector of vectors of ints t
    vector<int> flattened ; 
    for (int r = 0 ; r < tile.size() ; r++) { 
        for (int c = 0 ; c < tile[0].size() ; c++) { 
            if (tile[r][c] != 0) flattened.push_back(tile[r][c]) ; 
        }
    }
    return flattened ; 
}

int inversions(vector<int> flattened) { 
    int inversion_count = 0 ; 
    for (int l = 0 ; l < flattened.size() ; l++) { 
        for (int r = l + 1 ; r < flattened.size() ; r++) { 
            if (flattened[l] > flattened[r]) inversion_count++ ; 
        }
    }
    return inversion_count ; 
}

bool solvable_puzzle( vector<vector<int>> tile ) { 
    // return True if tiling t (list of lists of ints) is solvable
    // otherwise return False

    // case 1 : row = odd , inversions = even , 0 can be in any row 
    if ((tile.size() % 2 != 0) && (inversions(flatten_tile(tile)) % 2 == 0)) return true ; 

    // case 2 : row = even , inversions = odd , 0 in even row 
    else if ((tile.size() % 2 == 0) && (inversions(flatten_tile(tile)) % 2 != 0) && (row_number(tile , 0) % 2 == 0) ) return true ; 

    // case 3 : row = even . inversions = even , 0 in odd row 
    else if ((tile.size() % 2 == 0) && (inversions(flatten_tile(tile)) % 2 == 0) && (row_number(tile , 0) % 2 != 0) ) return true ; 

    // otherwise , return false
    else return false ; 
}

int main() { 
    vector<vector<int>> tile_puzzle = { {0,8,7} , {6,5,4} , {3,2,1} } ;
    
    // row_number test 
    cout << row_number(tile_puzzle , 0) << endl ; // 0 

    // flatten_tile test 
    vector<int> flattened = flatten_tile(tile_puzzle) ;

    string output = "[" ; for (auto num : flattened) output += to_string(num) + ", " ;
    output.pop_back() ; output.pop_back() ; output += "]" ; cout << output << endl ; // [8, 7, 6, 5, 4, 3, 2, 1]

    // inversions test 
    cout << inversions(flattened) << endl ; // 28 

    // solvable test 
    cout << solvable_puzzle(tile_puzzle) << endl ; // 1 = True
}