//#include <cstdlib>
#include <malloc.h>

int main() {
  void* p = malloc(1234);
  free(p);
}
