#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;

int get_second_min(stack<int> &s) {
    //write only in this function, do not declare static
    stack<int> temp_min ; int min_value ;  

    // loop 1 : find min value first 
    min_value = s.top() ; // given min as toppest element
    while (!s.empty()) { 
        // update min value 
        if (s.top() < min_value) min_value = s.top() ; 
        // push to temp_min
        temp_min.push( s.top() ) ; 
        s.pop() ; 
    }

    // replace s with temp_min
    s = temp_min ; 

    stack<int> temp_second_min ; int second_min_value ; 
    // then store to min_stack 

    second_min_value = 1e100 ; // given second_min value as much as it can
    while( !s.empty() ) { 
        // update value 
        if ((s.top() < second_min_value) && (s.top() > min_value)) {
            second_min_value = s.top() ; 
        }
        // push to temp_second_min
        temp_second_min.push( s.top() ) ; 
        s.pop() ; 
    }

    // replace s with temp_second_min
    s = temp_second_min ; 

    return second_min_value ; 
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    //repeat n-1 times
    for (int last = 1;last < n;last+=1) {
        stack<int> s;
        //build s;
        bool distinct = false;
        for (int i = last;i >= 0;i--) {
            s.push(v[i]);
            if (v[i] != v[0]) distinct = true;
        }

    cout << "--use v[" << last << "] to v[0] --" << "\n";
        if (distinct) {
            //call get_second_min if we have at least 2 distinct value
            int answer = get_second_min(s);

            //print result and s
            cout << "result is " << answer << "\n";
            cout << "size of s is " << s.size() << "\n" << "member of s are ";
            while(s.size() > 0) {
                cout << s.top() << " ";
                s.pop();
            }
            cout << "\n";
        } 
        else {
            cout << "skip because s has only one value\n\n\n";
        }
    }
    
    return 0;
}