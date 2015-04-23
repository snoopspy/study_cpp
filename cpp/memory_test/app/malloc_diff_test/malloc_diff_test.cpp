#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  char* prev = nullptr;
  for (size_t i = 0; i < 128; i++) {
    char* now = (char*)malloc(i);
    if (prev == nullptr) prev = now;
    cout << "i=" << i << " now=" << (void*)now << " diff=" << now - prev << endl;
    prev = now;
  }
}
