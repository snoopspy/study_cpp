#include <GStackTrace>
#include "foo1.h"

int foo1(int i) {
  GStackTrace::instance().dump();
  return i * 2;
}
