#include "myallocator.h"

void simple_test() {
  MyAllocator<char> a;
  char* p = a.allocate(1234);
  a.deallocate(p, 1234);
}

void string_test() {

}

int main() {
  simple_test();
  string_test();
}
