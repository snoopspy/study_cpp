#include "foo1.h"
#include "gstacktrace.h"

int foo1(int i) {
  GStackTrace::instance().dump();
  return i * 2;
}
