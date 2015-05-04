#include <iostream>
#include "obj1.h"
#include "obj2.h"

using namespace std;

int main() {
  cout << "beg main\n";
  Obj1::instance().foo();
  Obj2::instance().foo();
  cout << "end main\n";
}
