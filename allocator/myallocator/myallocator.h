#include <memory>

template<typename T>
class MyAllocator : public std::allocator<T> {
public:
  T* allocate(size_t n, const void* p = 0) {
    printf("MyAllocator::allocate(%zu, %p)\n", n, p);
    return static_cast<T*>(::operator new(n * sizeof(T)));
  }

  void deallocate(T* p, size_t size) {
    printf("MyAllocator::deallocate(%p, %zu)\n", p, size);
    ::operator delete(p);
  }
};
