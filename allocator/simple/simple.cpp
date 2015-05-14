#include <memory>

int main() {
  std::allocator<char> a;
  char* p = a.allocate(1234);
  a.deallocate(p, 1234);
}
