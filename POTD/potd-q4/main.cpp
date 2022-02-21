#include <iostream>
#include "Circle.h"
#include "q4.h"

void pass_by_value(Circle c) {
    cout<<"In main, the memory address of c is: "<<(&c)<<endl;

};
  void pass_by_pointer(Circle* ptr) {
      cout<<"In main, the memory address of c is: "<<(&ptr)<<endl;

  };
  void pass_by_ref(Circle &c){
      cout<<"In main, the memory address of c is: "<<(&c)<<endl;

  };

using namespace std;

int main() {
  Circle c;
  c.setRadius(5);

  Circle *ptr = &c;
  Circle& ref = c;

  pass_by_value(c);
  pass_by_pointer(ptr);
  pass_by_ref(ref);

  return 0;
}
