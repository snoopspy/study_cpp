#include <list>
#include <mutex>
#include <thread>
#include <glog/logging.h>

using namespace std;

class Obj1 {
protected:
  int n_;
public:
  Obj1(int n) : n_(n)  { DLOG(INFO) << "Obj1::Obj1  " << n_; }
  ~Obj1() { DLOG(INFO) << "Obj1::~Obj1 " << n_; }
};

class Obj2 {
protected:
  int n_;
public:
  Obj2(int n): n_(n)  { DLOG(INFO) << "Obj2::Obj2  " << n_; }
  ~Obj2() { DLOG(INFO) << "Obj2::~Obj2 " << n_; }
};

class Obj {
protected:
  int n_;
public:
  Obj(int n) : n_(n)  { DLOG(INFO) << "Obj::Obj  " << n; }
  ~Obj() { DLOG(INFO) << "Obj::~Obj " << n_; }

  std::shared_ptr<Obj1> obj1;
  std::shared_ptr<Obj2> obj2;
};

std::shared_ptr<Obj> g_obj = nullptr;
std::mutex g_mutex;

void change_global(int n) {
  std::shared_ptr<Obj> newObj = std::make_shared<Obj>(n);
  newObj->obj1 = std::make_shared<Obj1>(n);
  newObj->obj2 = std::make_shared<Obj2>(n);
  g_mutex.lock(); g_obj = newObj; g_mutex.unlock();
}

void change_proc() {
  this_thread::sleep_for(chrono::seconds(5));
  DLOG(INFO) << "";
  DLOG(INFO) << "beg change_proc";
  change_global(2);
  DLOG(INFO) << "end change_proc";
}

void obj1_proc() {
  DLOG(INFO) << "beg obj1_proc";
  std::shared_ptr<Obj1> obj1;
  {
    g_mutex.lock();
    std::shared_ptr<Obj> obj = g_obj;
    g_mutex.unlock();
    obj1 = obj->obj1;
  }
  this_thread::sleep_for(chrono::seconds(10));
  DLOG(INFO) << "";
  DLOG(INFO) << "end obj1_proc";
}

int main() {
  DLOG(INFO) << "beg main";
  change_global(1);

  thread change_thread = thread(change_proc);
  thread obj1_thread = thread(obj1_proc);

  change_thread.join();
  obj1_thread.join();

  DLOG(INFO) << "end main";
  return 0;
}
