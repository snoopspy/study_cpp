#include <string>

using namespace std;

namespace mmap_allocator_namespace
{
        template <typename T>
        class mmap_allocator: public std::allocator<T>
        {
public:
                typedef size_t size_type;
                typedef T* pointer;
                typedef const T* const_pointer;

                template<typename _Tp1>
                struct rebind
                {
                        typedef mmap_allocator<_Tp1> other;
                };

                pointer allocate(size_type n, const void *hint=0)
                {
                        fprintf(stderr, "Alloc %d bytes.\n", n*sizeof(T));
                        return std::allocator<T>::allocate(n, hint);
                }

                void deallocate(pointer p, size_type n)
                {
                        fprintf(stderr, "Dealloc %d bytes (%p).\n", n*sizeof(T), p);
                        return std::allocator<T>::deallocate(p, n);
                }

                mmap_allocator() throw(): std::allocator<T>() { fprintf(stderr, "Hello allocator!\n"); }
                mmap_allocator(const mmap_allocator &a) throw(): std::allocator<T>(a) { }
                template <class U>
                mmap_allocator(const mmap_allocator<U> &a) throw(): std::allocator<T>(a) { }
                ~mmap_allocator() throw() { }
        };
}

typedef  std::basic_string<char, std::char_traits<char>, mmap_allocator_namespace::mmap_allocator<char>> MyString;

/*
int main()
{
  std::string s;
  MyString ms;
  ms = "test";
  cout << "Hello World!" << endl;
  return 0;
}
*/
