#include <iostream>
#include <gstacktrace.h>

using namespace std;

int foo1(int i, int j) {
  return i / j;
}

int foo2(int i, int j) {
  return foo1(i, j);
}

int foo3(int i, int j) {
  return foo2(i, j);
}

int foo4(int i, int j) {
  return foo3(i, j);
}

int foo5(int i, int j) {
  return foo4(i, j);
}

int main() {
  GStackTrace::instance().setSignal(SIGFPE);
  int i, j; cin >> i >> j;
  int k = foo5(i, j);
  cout << k << endl;
}
