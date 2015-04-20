#include <iostream>
#include "obj2.h"

using namespace std;

Obj2::Obj2()     { cout << "Obj2::Obj2\n";  }
Obj2::~Obj2()    { cout << "Obj2::~Obj2\n"; }
void Obj2::foo() { cout << "Obj2::foo\n";   }

Obj2& Obj2::instance() {
  static Obj2 instance_;
  return instance_;
}
