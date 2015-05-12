#include <iostream>
#include <string>
#include "../../src/mymalloc.h"

using namespace std;

class MyNewString : public string {
public:
  MyNewString() {}
  MyNewString(const char* p) : string(p) {}

  void* operator new(size_t size) {
    cout << "MyNewString::new size=" << size << endl;
    return MyMalloc::instance().acquire(size);
  }

  void operator delete(void* ptr) {
    cout << "MyNewString::delete ptr=" << ptr << endl;
    MyMalloc::instance().release(ptr);
  }
};

class MyAllocString : public basic_string<char, char_traits<char>, allocator<char>> {
public:
  MyAllocString() {}
  MyAllocString(const char* p) : basic_string<char, char_traits<char>, allocator<char>>(p) {}
};

int main() {
  {
    cout << "----- string test -----\n";
    string s = "1";
  }
  {
    cout << "----- string pointer test -----\n";
    string* s = new string("1");
    delete s;
  }

  {
    cout << "----- MyNewString test -----\n";
    MyNewString s = "1";
  }
  {
    cout << "----- MyNewString pointer test -----\n";
    MyNewString* s = new MyNewString("1");
    delete s;
  }

  {
    cout << "----- MyAllocString test -----\n";
    MyAllocString s = "1";
  }
  {
    cout << "----- MyAllocString pointer test -----\n";
    MyAllocString* s = new MyAllocString("1");
    delete s;
  }
}
