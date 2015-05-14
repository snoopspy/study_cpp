#include <iostream>
#include "myallocator.h"

void simple_test() {
  MyAllocator<char> a;
  char* p = a.allocate(1234);
  a.deallocate(p, 1234);
}

void string_test() {
  typedef std::basic_string<char, std::char_traits<char>, MyAllocator<char> > MyString;
  MyString ms;
  ms = "hello world";
  std::cout << ms << std::endl;
}

int main() {
  //simple_test();
  string_test();
}
