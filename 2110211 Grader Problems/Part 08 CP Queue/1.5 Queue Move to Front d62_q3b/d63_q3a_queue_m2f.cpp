#include <stdio.h>
#include <iostream>
#include <vector>
#include "d63_q3a_queue_m2f_cp_queue_template.h"
#include "d63_q3a_queue_m2f_method.h"

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
      int p;
      scanf("%d", &p);
      q.move_to_front(p);
    }
    scanf("%c", &c);
  }
  return 0;
}
