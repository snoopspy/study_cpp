//#include <cstdlib>
#include <mymalloc.h>

int main() {
  void* p = malloc(1234);
  free(p);
}
