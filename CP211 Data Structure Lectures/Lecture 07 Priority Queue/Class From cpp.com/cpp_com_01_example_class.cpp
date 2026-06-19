// classes example
#include <iostream>
using namespace std;

class Rectangle {
    // default = private 
    // can access with method only , can't change value directly 
    int width, height;
  public:
    Rectangle (int,int); // constructor
    void set_values (int,int); // method1
    int area() {return width*height;} // method2
};

void Rectangle::set_values (int x, int y) { // class Rectangle method set_values 
  width = x;
  height = y;
}

Rectangle::Rectangle (int x , int y) {
    width = x ; 
    height = y ; 
}

int main () {
  Rectangle rect1(3,4);
  rect1.set_values(4,5);
  cout << "area: " << rect1.area(); // value changed with method
  return 0;
}