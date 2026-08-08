#include <iostream>
#include <vector>
using namespace std;
void cross_2d(vector<vector<int>> &m ,int r1, int r2, int c1, int c2) {
        // purpose : delete row from r1 <= ri <= r2 and c1 <= cj <= c2
        
    // delete row first using vector erase 
    if (r1 <= r2) m.erase( m.begin() + r1 , m.begin() + r2 + 1) ; 
    
    // check column 
    if (c1 <= c2) { 
        // loop each row then delete nominated column
        for (int r = 0 ; r < m.size() ; r++) { 
            // delete each column with erase 
            vector<int> data_in_row = m[r] ; 
            data_in_row.erase( data_in_row.begin() + c1 , data_in_row.begin() + c2 + 1 ) ; 
            m[r] = data_in_row ; // Don't forget to replace back to vector
        }
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    vector<vector<int>> m;
    int r,c,r1,r2,c1,c2;
    cin>> r >> c;
    cin >> r1 >> r2 >> c1 >> c2;
    m.resize(r);

    for (int i =0;i < r;i++) {
        m[i].resize(c);
        for (int j = 0;j < c;j++) {
            cin >> m[i][j];
        }
    }
    cross_2d(m,r1,r2,c1,c2);
    for (int i =0;i < m.size();i++) {
        for (int j = 0;j < m[i].size();j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}