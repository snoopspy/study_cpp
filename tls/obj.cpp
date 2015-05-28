#include "obj.h"

Simple s;
Complx c;
__thread Simple ts;
//__thread Complx tc; // error: non-local variable 'tc' declared '__thread' needs dynamic initialization
thread_local Simple tls;
thread_local Complx tlc;

Simple* ps;
Complx* pc;
__thread Simple* pts;
__thread Complx* ptc;
thread_local Simple* ptls;
thread_local Complx* ptlc;

void initPointer() {
  ps = new Simple;
  pc = new Complx;
  pts = new Simple;
  ptc = new Complx;
  ptls = new Simple;
  ptlc = new Complx;
}
