#include <iostream>
#include "vector_test.h"

using namespace std;

template <int N>
void _vector_test() {
  cout << "vector<char[" << N << "]>" << endl;
  vector<Char<N>> l;
  Char<N> item;
  l.push_back(item);
}

void vector_test() {
  _vector_test<1>();
  _vector_test<2>();
  _vector_test<3>();
  _vector_test<4>();
  _vector_test<5>();
  _vector_test<6>();
  _vector_test<7>();
  _vector_test<8>();
  _vector_test<9>();
  _vector_test<10>();
  _vector_test<11>();
  _vector_test<12>();
  _vector_test<13>();
  _vector_test<14>();
  _vector_test<15>();
  _vector_test<16>();
  _vector_test<17>();
  _vector_test<18>();
  _vector_test<19>();
  _vector_test<20>();
}
