#include <iostream>
#include "list_test.h"

using namespace std;

template <int N>
void _list_test() {
  cout << "list<char[" << N << "]>" << endl;
  list<Char<N>> l;
  Char<N> item;
  l.push_back(item);
}

void list_test() {
  _list_test<1>();
  _list_test<2>();
  _list_test<3>();
  _list_test<4>();
  _list_test<5>();
  _list_test<6>();
  _list_test<7>();
  _list_test<8>();
  _list_test<9>();
  _list_test<10>();
  _list_test<11>();
  _list_test<12>();
  _list_test<13>();
  _list_test<14>();
  _list_test<15>();
  _list_test<16>();
  _list_test<17>();
  _list_test<18>();
  _list_test<19>();
  _list_test<20>();
}
