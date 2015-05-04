#include <cstdlib>

int main() {
  void* p = malloc(1234);
  free(p);
}
