#include <iostream>
#include <gstacktrace.h>

using namespace std;

int foo1(int i) {
  GStackTrace::instance().dump();
  return i * 2;
}

int foo2(int i) {
  return foo1(i);
}

int foo3(int i) {
  return foo2(i);
}

int foo4(int i) {
  return foo3(i);
}

int foo5(int i) {
  return foo4(i);
}

int main() {
  int i; cin >> i;
  int j = foo5(i);
  cout << j << endl;
}
