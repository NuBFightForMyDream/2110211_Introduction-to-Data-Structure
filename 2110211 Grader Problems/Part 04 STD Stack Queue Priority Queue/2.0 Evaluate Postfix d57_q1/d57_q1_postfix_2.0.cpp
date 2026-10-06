#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#include "d57_q1_postfix_template.h"

int main() {
  vector<pair<int,int> > v;
  int n,a,b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    v.push_back(make_pair(a,b));
  }
  cout << eval_postfix(v) << endl;
}

/* 
7
1 1
1 2
1 3
1 4
0 0
0 0
0 0
*/