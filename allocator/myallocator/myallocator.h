#include <memory>
#include <iostream>

template <typename T>
struct MyAllocator : std::allocator<T>
{
  MyAllocator() {}
  template <typename U> MyAllocator(MyAllocator<U> const&) {}

  typedef T value_type;
  template <typename U> struct rebind { typedef MyAllocator<U> other; };
  T* allocate(size_t n) {
    T* res = static_cast<T*>(operator new(n*sizeof(T)));
    std::cout << "MyAllocator::allocate   " << (void*)res << " " << n << std::endl;
    return res;
  }
  void deallocate(T* p, size_t size) {
    std::cout << "MyAllocator::deallocate " << (void*)p << " " << size << std::endl;
    operator delete(p);
  }
};
