#include <iostream>
int func_a(int p) {
    int sum = 0;
    for (int i = 1;i < p;i++)
    sum += i;
    return sum;
}
int func_b(int p) {
    int a = func_a(p);
    return a * 10;
}
int main() {
    int x1 = func_a(5);
    std::cout << x1 << std::endl;
    int x2 = func_b(5); // call func_a
    std::cout << x2 << std::endl;
}