#include <iostream>
#include <mystr.h>

int main() {
  MyStr ms = "hello world";
  std::cout << ms.c_str() << std::endl;
}
