#include <memory>

int main() {
  std::allocator<char> a;
  std::allocator<char>::pointer p = a.allocate(1234);
  a.deallocate(p, 1234);
}
