#include <iostream>

using namespace std;

int multiply(int n) {
  return n * 2;
}

int main() {
  int i; cin >> i;
  int j = multiply(i);
  cout << j << endl;
}
