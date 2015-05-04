#include <iostream>
#include "malloc.h"

using namespace std;

Malloc::Malloc() {
  idx_ = 0;
}

void* Malloc::acquire(size_t size) {
  if (idx_ + size >= BUF_SIZE) {
    cout << "idx_ is " << idx_ << endl;
    return nullptr;
  }
  void* res = &buf_[idx_];
  idx_ += size;
  cout << "Malloc::acquire " << res << " size=" << size << endl;
  return res;
}

void Malloc::release(void* ptr) {
  cout << "Malloc::release " << ptr << endl;
}

Malloc& Malloc::instance() {
  static Malloc malloc;
  return malloc;
}

void* malloc(size_t size) {
  return Malloc::instance().acquire(size);
}

void free(void* ptr) {
  Malloc::instance().release(ptr);
}
