#pragma once

#include <string.h>

class MyStr {
protected:
  char* buf_;
public:
  MyStr() {
    buf_ = nullptr;
  }

  MyStr(const char* p) {
    buf_ = strdup(p);
  }

  ~MyStr() {
    if (buf_ != nullptr) {
      free(buf_);
      buf_ = nullptr;
    }
  }

  const char* c_str() {
    return buf_;
  }
};
