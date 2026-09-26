#include "d66_q2b_stack_reverse_cp_stack_template.h"
#include "d66_q2b_stack_reverse_method_reverse.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, first, last;
	cin >> N >> first >> last;

	CP::stack<int > s;
	for(int i=1;i<=N;i++)
		s.push(i);

	s.reverse(first, last);

	s.print();
}