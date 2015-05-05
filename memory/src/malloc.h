#pragma once

#include <cstddef> // for size_t

class Malloc {
  static constexpr size_t BUF_SIZE = 1024 * 1024;
  char buf_[BUF_SIZE];
  int idx_;

public:
  Malloc();
  void* acquire(size_t size);
  void release(void* ptr);

public:
  static Malloc& instance();
};
