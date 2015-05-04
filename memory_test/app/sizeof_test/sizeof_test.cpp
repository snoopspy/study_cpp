#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <vector>

using namespace std;

void primitive_test() {
  cout << "char      = " << sizeof(char) << endl;
  cout << "short     = " << sizeof(short) << endl;
  cout << "int       = " << sizeof(int) << endl;
  cout << "long      = " << sizeof(long) << endl;
  cout << "long long = " << sizeof(long long) << endl;

  cout << "float     = " << sizeof(float) << endl;
  cout << "double    = " << sizeof(double) << endl;

  cout << "void*     = " << sizeof(void*) << endl;
}

/*
void container_test() {
  array_test();
  dequeue_test();
  forward_list_test();
  list_list();
  map_test();
  queue_test();
  set_set();
  stack_test();
  unordered_map_test();
  unordered_set_test();
  vector_test();
}
*/

void list_test() {
  cout << "list<int>       = " << sizeof(list<int>) << endl;
  cout << "list<char[1]>   = " << sizeof(list<char[1]>) << endl;
  cout << "list<char[100]> = " << sizeof(list<char[100]>) << endl;
}

void vector_test() {
  cout << "vector<int>       = " << sizeof(vector<int>) << endl;
  cout << "vector<char[1]>   = " << sizeof(vector<char[1]>) << endl;
  cout << "vector<char[100]> = " << sizeof(vector<char[100]>) << endl;
}

void set_test() {
  cout << "set<int>       = " << sizeof(set<int>) << endl;
  cout << "set<char[1]>   = " << sizeof(set<char[1]>) << endl;
  cout << "set<char[100]> = " << sizeof(set<char[100]>) << endl;
}

void map_test() {
  cout << "map<int, int>       = " << sizeof(map<int, int>) << endl;
  cout << "map<int, char[1]>   = " << sizeof(map<int, char[1]>) << endl;
  cout << "map<int, char[100]> = " << sizeof(map<int, char[100]>) << endl;

  cout << "map<char[1], int>       = " << sizeof(map<char[1], int>) << endl;
  cout << "map<char[1], char[1]>   = " << sizeof(map<char[1], char[1]>) << endl;
  cout << "map<char[1], char[100]> = " << sizeof(map<char[1], char[100]>) << endl;

  cout << "map<char[100], int>       = " << sizeof(map<char[100], int>) << endl;
  cout << "map<char[100], char[1]>   = " << sizeof(map<char[100], char[1]>) << endl;
  cout << "map<char[100], char[100]> = " << sizeof(map<char[100], char[100]>) << endl;
}

void string_test() {
  cout << "string  = " << sizeof(string) << endl;
  cout << "wstring = " << sizeof(wstring) << endl;
}

int main() {
  primitive_test();
  list_test();
  vector_test();
  set_test();
  map_test();
  string_test();
}
