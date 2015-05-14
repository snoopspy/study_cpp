#include <memory>

void simple() {
  std::allocator<char> a;
  std::allocator<char>::pointer p = a.allocate(1234);
  a.deallocate(p, 1234);
}

template<typename _Tp>
class MyAllocator : public std::allocator<_Tp> {
};

void inherit() {
  MyAllocator<char> a;
  std::allocator<char>::pointer p = a.allocate(5678);
  a.deallocate(p, 5678);
}

int main() {
  simple();
  inherit();
}
