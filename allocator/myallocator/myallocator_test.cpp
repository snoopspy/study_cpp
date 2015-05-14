#include <iostream>
#include <list>
#include "myallocator.h"

void simple_test() {
  MyAllocator<char> a;
  char* p = a.allocate(1234);
  a.deallocate(p, 1234);
}

void string_test() {
  std::string s;
  typedef std::basic_string<char, std::char_traits<char>, MyAllocator<char> > MyString;
  MyString ms;
  ms = "hello world";
  std::cout << ms << std::endl;
}

struct Obj { char buf[256]; };
void list_test() {
  //std::list<int> intList;
  std::list<Obj, MyAllocator<Obj> > myIntList;
  Obj obj;
  myIntList.push_back(obj);
  myIntList.push_back(obj);
}

int main() {
  //simple_test();
  //string_test();
  list_test();
}
