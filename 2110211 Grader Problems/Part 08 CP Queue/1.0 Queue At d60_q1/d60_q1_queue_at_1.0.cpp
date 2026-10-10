#include <stdexcept>
#include <iostream>
#include "d60_q1_queue_at_cp_queue_template.h"
#include "d60_q1_queue_at_method.h"
#include <vector>

int main() {
  CP::queue<int> q;
  char cmd;
  do {
    int a;
    std::cin >> cmd;
    switch(cmd) {
      case 'a':
        std::cin >> a;
        q.push(a);
        break;
      case 'd':
        q.pop();
        break;
      case 'k':
        std::cin >> a;
        std::cout << "Data at " << a << " is " << q[a] << std::endl;
        break;
      case 'p':
        q.print();
        break;
      case 'q':
        break;
      default:
        std::cout << "WRONG COMMAND" << std::endl;
    }

  } while (cmd != 'q');
  std::cout << "Exit" << std::endl;
}

