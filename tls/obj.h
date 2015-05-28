#pragma once

struct Obj {
  Obj() {}
};

struct Simple {
  int a_ { 1 };
  int b_ { 2 };
  int c_ { 3 };
};

struct Complx {
  int a_ { 4 };
  int b_ { 5 };
  int c_ { 6 };
  Obj obj_;
};

extern Simple s;
extern Complx c;
extern __thread Simple ts;
extern __thread Complx tc;
extern thread_local Simple tls;
extern thread_local Complx tlc;

extern Simple* ps;
extern Complx* pc;
extern __thread Simple* pts;
extern __thread Complx* ptc;
extern thread_local Simple* ptls;
extern thread_local Complx* ptlc;

void initPointer();
