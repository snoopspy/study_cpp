#include <iostream>

struct Obj {
  Obj() {}
};

struct Simple {
  int i_ { 1 };
};

struct Complex {
  int i_ { 2 };
  Obj obj_;
};

struct __thread_Simple {
  int i_ { 3 };
};

struct __thread_Complex {
  int i_ { 4 };
  Obj obj_;
};

struct thread_local_Simple {
  int i_ { 5 };
};

struct thread_local_Complex {
  int i_ { 6 };
  Obj obj_;
};

Simple s;
Complex c;
__thread __thread_Simple ts;
// __thread __thread_Complex tc; error: non-local variable 'tc' declared '__thread' needs dynamic initialization
thread_local thread_local_Simple tls;
thread_local thread_local_Complex tlc;

int main() {
  int i;

  i = s.i_;
  //0x400845  <+0x0008>        8b 05 0d 08 20 00        mov    0x20080d(%rip),%eax        # 0x601058 <s>
  //0x40084b  <+0x000e>        89 45 fc                 mov    %eax,-0x4(%rbp)
  std::cout << i << std::endl;

  i = c.i_;
  //0x400874  <+0x0037>        8b 05 e6 07 20 00        mov    0x2007e6(%rip),%eax        # 0x601060 <c>
  //0x40087a  <+0x003d>        89 45 fc                 mov    %eax,-0x4(%rbp)
  std::cout << i << std::endl;

  i = ts.i_;
  //0x4008a3  <+0x0066>        64 8b 04 25 ec ff ff ff  mov    %fs:0xffffffffffffffec,%eax
  //0x4008ab  <+0x006e>        89 45 fc                 mov    %eax,-0x4(%rbp)
  std::cout << i << std::endl;

  i = tls.i_;
  //0x4008d4  <+0x0097>        64 8b 04 25 f0 ff ff ff  mov    %fs:0xfffffffffffffff0,%eax
  //0x4008dc  <+0x009f>        89 45 fc                 mov    %eax,-0x4(%rbp)
  std::cout << i << std::endl;

  i = tlc.i_;
  //0x400905  <+0x00c8>        e8 2c 01 00 00           callq  0x400a36 <_ZTW3tlc>
  //0x40090a  <+0x00cd>        8b 00                    mov    (%rax),%eax
  //0x40090c  <+0x00cf>        89 45 fc                 mov    %eax,-0x4(%rbp)
  std::cout << i << std::endl;
}
