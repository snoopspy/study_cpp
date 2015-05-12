#pragma once

#include <cstddef> // for size_t

class MyMalloc {
  static constexpr size_t BUF_SIZE = 1024 * 1024;
  char buf_[BUF_SIZE];
  int idx_;

public:
  MyMalloc();
  void* acquire(size_t size);
  void release(void* ptr);

public:
  static MyMalloc& instance();
};

#ifdef __cplusplus
extern "C"
{
#endif

void* malloc(size_t size) __THROW;
void free(void* ptr) __THROW;

#ifdef __cplusplus
}
#endif
