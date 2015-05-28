#include <iostream>

struct Obj {
  Obj() {}
};

struct __thread_Simple {
  int i { 1 };
};

struct __thread_Complex {
  int i { 2 };
  Obj obj_;
};

struct thread_local_Simple {
  int i { 3 };
};

struct thread_local_Complex {
  int i { 4 };
  Obj obj_;
};

__thread __thread_Simple ts;
// __thread __thread_Complex tc; error: non-local variable 'tc' declared '__thread' needs dynamic initialization
thread_local thread_local_Simple tls;
thread_local thread_local_Complex tlc;

int main() {
  int i;

  i = ts.i;
  //0x400845  <+0x0008>        64 8b 04 25 ec ff ff ff  mov    %fs:0xffffffffffffffec,%eax
  //0x40084d  <+0x0010>        89 45 fc                 mov    %eax,-0x4(%rbp)
  std::cout << i << std::endl;

  i = tls.i;
  //0x400876  <+0x0039>        64 8b 04 25 f0 ff ff ff  mov    %fs:0xfffffffffffffff0,%eax
  //0x40087e  <+0x0041>        89 45 fc                 mov    %eax,-0x4(%rbp)
  std::cout << i << std::endl;

  i = tlc.i;
  //0x4008a7  <+0x006a>        e8 f8 00 00 00           callq  0x4009a4 <_ZTW3tlc>
  //0x4008ac  <+0x006f>        8b 00                    mov    (%rax),%eax
  //0x4008ae  <+0x0071>        89 45 fc                 mov    %eax,-0x4(%rbp)
  std::cout << i << std::endl;
}
