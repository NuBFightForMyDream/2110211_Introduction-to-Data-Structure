#include <iostream>
#include <vector>
#include "d60_q1_vuniq_cp_vector_template.h"
#include "d60_q1_vuniq_method_uniq.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  CP::vector<int> v1;
  //read vector
  int n1,a;
  scanf("%d",&n1);
  v1.resize(n1);
  for (int i = 0;i < n1;i++) {
    scanf("%d",&a);
    v1[i] = a;
  }

  v1.uniq();

  //display result;
  printf("Result\n");
  for (auto &x : v1) {
    printf("%d ",x);
  }
  printf("\n");

  return 0;
}
