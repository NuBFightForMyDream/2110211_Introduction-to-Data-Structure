#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT

  stack<int> storage ; 

  // vector be like this : <(1,1), (1,2), (1,3), (1,4), (0,0), (0,0), (0,0)>
  for (auto &[type , value] : v) { // type = v[i].first , value = v[i].second

    // if operand , push to storage 
    if (type == 1) { 
        storage.push(value) ; 
    }

    else { // check type of operand
      // then pop 2 elements out for calculaion , then push result back in storage
      int operand_2 = storage.top() ; storage.pop() ; 
      int operand_1 = storage.top() ; storage.pop() ; 

      int result = 0 ;

      if (value == 0) { // plus
        result = operand_1 + operand_2 ; 
      } 
      else if (value == 1) { // minus
        result = operand_1 - operand_2 ; 
      }
      else if (value == 2) { // multiply
        result = operand_1 * operand_2 ; 
      }
      else if (value == 3) { // floor division 
        result = operand_1 / operand_2 ; 
      }
          
      // push result to storage
      storage.push(result) ; 

    }
  }

  // return value
  int val_out = storage.top() ; 
  return val_out ; 

}

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
