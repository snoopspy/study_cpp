#pragma once

class Obj1
{
protected:
  Obj1();
  ~Obj1();

public:
  void foo();

protected:
  static Obj1 instance_;
public:
  static Obj1& instance();
};
