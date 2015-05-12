#include <iostream>
#include "mymalloc.h"

using namespace std;

MyMalloc::MyMalloc() {
  idx_ = 0;
}

void* MyMalloc::acquire(size_t size) {
  if (idx_ + size >= BUF_SIZE) {
    cout << "idx_ is " << idx_ << endl;
    return nullptr;
  }
  void* res = &buf_[idx_];
  idx_ += size;
  cout << "MyMalloc::acquire " << res << " size=" << size << endl;
  return res;
}

void MyMalloc::release(void* ptr) {
  cout << "MyMalloc::release " << ptr << endl;
}

MyMalloc& MyMalloc::instance() {
  static MyMalloc malloc;
  return malloc;
}

#ifdef __cplusplus
extern "C"
{
#endif

void* malloc(size_t size) __THROW  {
  return MyMalloc::instance().acquire(size);
}

void free(void* ptr) __THROW {
  MyMalloc::instance().release(ptr);
}

#ifdef __cplusplus
}
#endif


