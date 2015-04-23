#pragma once

template <int N>
struct Char {
  Char(int c = 0) {
    for (int i = 0; i < N; i++) buf[i] = c;
  }
  char buf[N];
};
