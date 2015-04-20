#include <iostream>
#include <string>

using namespace std;

struct Person {
  int age;
  string name;
  string country;
  string address;
  string tel;

  /*
  void setProperty(string name, string value) {
    if (name == "age") age = stoi(value);
    else if (name == "name") name = value;
    else if (name == "country") country = value;
    else if (name == "address") address = value;
    else if (name == "tel") tel = value;
    else cout << "Invalid attribute " << name << endl;
  }
  */

  static constexpr uint32_t const_hash(const char *p) {
    return *p ? static_cast<uint32_t>(*p) + 33 * const_hash(p + 1) :  5381;
  }

  void setProperty(string name, string value) {
    uint32_t hash = const_hash(name.c_str());
    switch (hash) {
      case const_hash("age"):     if (name == "age") age = stoi(value); break;
      case const_hash("name"):    if (name == "name") name = value; break;
      case const_hash("country"): if (name == "country") country = value; break;
      case const_hash("address"): if (name == "address") address = value; break;
      case const_hash("tel"):     if (name == "tel") tel = value; break;
      default: cout << "Invalid attribute " << name << endl;
    }
  }
};

int main()
{
  Person person;
  person.setProperty("age", "33");
  person.setProperty("name", "gilgil");
  return 0;
}
