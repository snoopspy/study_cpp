#include <iostream>
#include "obj.h"

void write(int n) {
  std::cout << n << std::endl;
}

int main() {
  int n;

  {
    n = s.b_;
    write(n);

    n = c.b_;
    write(n);

    n = ts.b_;
    write(n);

    n = tls.b_;
    write(n);

    n = tlc.b_;
    write(n);
  }

  initPointer();
  {
    n = ps->b_;
    write(n);

    n = pc->b_;
    write(n);

    n = pts->b_;
    write(n);

    n = ptc->b_;
    write(n);

    n = ptls->b_;
    write(n);

    n = ptlc->b_;
    write(n);
  }
}
