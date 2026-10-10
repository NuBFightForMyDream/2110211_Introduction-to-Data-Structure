#include <cstdio>
#include <utility>
#include <vector>

#include "d69_q2a_stack_super_push_cp_stack_template.h"
#include "d69_q2a_stack_super_push_method
.h"

int valueOf(int x) { return x; }

template <typename T>
void run(int q) {
	CP::stack<T> s;
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {            // 1 x c
			int x, c;
			scanf("%d %d", &x, &c);
			s.push(T(x), c);
		} else if (op == 2) {     // 2 k x1 c1 ... xk ck
			int k;
			scanf("%d", &k);
			std::vector<std::pair<T, int>> elements;
			elements.reserve(k);
			for (int i = 0; i < k; i++) {
				int x, c;
				scanf("%d %d", &x, &c);
				elements.emplace_back(x, c);
			}
			s.push(std::move(elements));
		} else if (op == 3) {     // 3 m
			int m;
			scanf("%d", &m);
			while (m--) s.pop();
		} else if (op == 4) {     // 4
			if (s.empty()) printf("empty\n");
			else printf("%d %d\n", (int)s.size(), valueOf(s.top()));
		}
	}

	// final stack, top to bottom, run-length encoded
	printf("%d\n", (int)s.size());
	while (!s.empty()) {
		int x = valueOf(s.top());
		int c = 0;
		while (!s.empty() && valueOf(s.top()) == x) {
			s.pop();
			c++;
		}
		printf("%d %d\n", x, c);
	}
}

int main(int argc, char *argv[]) {
	int type, q;
	scanf("%d %d", &type, &q);
	run<int>(q);  // type is ignored here: the output never depends on the element type
	return 0;
}
