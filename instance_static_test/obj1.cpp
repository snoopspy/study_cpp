#include <iostream>
#include "obj1.h"

using namespace std;

Obj1::Obj1()     { cout << "Obj1::Obj1\n";  }
Obj1::~Obj1()    { cout << "Obj1::~Obj1\n"; }
void Obj1::foo() { cout << "Obj1::foo\n";   }

Obj1& Obj1::instance() {
  return instance_;
}
Obj1 Obj1::instance_; // global static object
