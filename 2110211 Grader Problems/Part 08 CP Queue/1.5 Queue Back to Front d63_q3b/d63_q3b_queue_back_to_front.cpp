#include <iostream>
#include <vector>
#include "d63_q3b_queue_back_to_front_cp_queue_template.h"
#include "d63_q3b_queue_back_to_front_method.h"
#include <stdio.h>

using namespace std;

int main() {
  CP::queue<int> q;
  char c;
  scanf("%c", &c);
  while (c != 'q') {
    if (c == 'u') {
      // add data
      int v;
      scanf("%d", &v);
      q.push(v);
    } else if (c == 'o') {
      q.pop();
    } else if (c == 'p') {
      q.print();
    } else if (c == 'm') {
      q.back_to_front();
    }
    scanf("%c", &c);
  }
  return 0;
}
