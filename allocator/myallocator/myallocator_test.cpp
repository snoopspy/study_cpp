#include <iostream>
#include <list>
#include <map>
#include "myallocator.h"

void simple_test() {
  MyAllocator<char> a;
  char* p = a.allocate(1234);
  a.deallocate(p, 1234);
}

void string_test() {
  std::basic_string<char, std::char_traits<char>, MyAllocator<char> > ms;
  ms = "hello world";
  std::cout << ms << std::endl;
}

struct Obj { char buf[256]; };
void list_test() {
  std::list<Obj, MyAllocator<Obj> > myList;
  myList.push_back(Obj());
  myList.push_back(Obj());
}

void map_test() {
  std::map<int, Obj, std::less<int>, MyAllocator<std::pair<int, Obj>>> myMap;

  myMap[0] = Obj();
  myMap[1] = Obj();
}

int main() {
  //simple_test();
  //string_test();
  //list_test();
  map_test();
}
