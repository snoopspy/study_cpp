#include <iostream>
#include <foo5.h>
#include <gstacktrace.h>

using namespace std;

int main() {
  GStackTrace::instance().setSignal(SIGFPE);
  int i, j; cin >> i >> j;
  int k = foo5(i, j);
  cout << k << endl;
}
