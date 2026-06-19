# include <iostream>
# include <vector> 
# include <queue> 
# include <map> 
using namespace std ; 

void showSolution(int val, map<int,int>& prev) {
    // now val = tagret
    string out = "";
    while(prev[val] != -1) {
        if (prev[val] * 3 == val) {
            out = "x3" + out;
        } 
        else {
            out = "/2" + out;
        }
        val = prev[val]; // update val 
    }
    out = "1" + out;
    cout << out << endl;
}

// simulating multiply 3 and dividing 2 with "Breadth First Search"
void m3d2(int target) {
    // define map of node and subnode for each value 
    map<int, int> prev; // [x,prev_x] , [x,prev_x] , ...
    queue<int> q; // q represent for found number
    
    // define initial value 1:-1
    int v = 1;
    q.push(1); prev[1] = -1;

    while( !q.empty() ) {
        // get first value then pop out from queue (to add m3d2)
        v = q.front(); q.pop();

        // if value ever found , break out 
        if (v == target) break;

        // find d2 and m3 value 
        int v2 = v/2;
        int v3 = v*3;

        // find if value ever found (key won't be 0 if ever found)
        // bcz 0 cant make subnode and default value is 0
        if (prev[v2] == 0) {q.push(v2); prev[v2] = v;}
        if (prev[v3] == 0) {q.push(v3); prev[v3] = v;}
    }
    if (v == target) showSolution(v, prev);
}

int main() {
	// your code goes here
	int target;
    cout << "Enter target: " << endl;
    cin >> target;
    m3d2(target);
    return 0;

}

