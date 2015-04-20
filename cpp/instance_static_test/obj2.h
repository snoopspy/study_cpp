#pragma once

class Obj2
{
protected:
  Obj2();
  ~Obj2();

public:
  void foo();

public:
  static Obj2& instance();
};
