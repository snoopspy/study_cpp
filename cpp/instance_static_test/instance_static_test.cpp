#include <iostream>

using namespace std;

class Obj1 {
protected:
  Obj1()  { cout << "Obj1::Obj1\n";   }
  ~Obj1() { cout << "Obj1::~Obj1\n";  }
  static Obj1 instance_;
public:
  void foo() { cout << "Obj1::foo\n"; }
  static Obj1& instance() {
    return instance_;
  }
};
Obj1 Obj1::instance_;

class Obj2 {
protected:
  Obj2()  { cout << "Obj2::Obj2\n";  }
  ~Obj2() { cout << "Obj2::~Obj2\n"; }
public:
  void foo() { cout << "Obj2::foo\n"; }
  static Obj2& instance() {
    static Obj2 instance_;
    return instance_;
  }
};

int main() {
  cout << "beg main\n";
  Obj1::instance().foo();
  Obj2::instance().foo();
  cout << "end main\n";
}
