#include "mymalloc.h"

#ifdef __cplusplus
extern "C"
{
#endif

void* malloc(size_t size) throw() {
  return MyMalloc::instance().acquire(size);
}

void free(void* ptr) throw() {
  MyMalloc::instance().release(ptr);
}

#ifdef __cplusplus
}
#endif
