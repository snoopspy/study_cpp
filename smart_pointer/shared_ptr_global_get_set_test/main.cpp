#include <mutex>
#include <thread>
#include <glog/logging.h>

using namespace std;

class Obj {
  static constexpr int SIZE = 1024;
protected:
  int arr[SIZE];
public:
  Obj(int n) {
    for (int i = 0; i < SIZE; i++) arr[i] = n;
  }
  void check() {
    int first = arr[0];
    for (int i = 0; i < SIZE; i++) {
      if (first != arr[i]) {
        LOG(ERROR) << "first=" << first << " arr[" << i << "]=" << arr[i] << " " << (void*)this;
      }
    }
  }
};
std::shared_ptr<Obj> g_obj = nullptr;
std::mutex g_mutex;

void write_proc() {
  constexpr int CNT = 1000000;
  for (int i = 0; i < CNT; i++) {
    std::shared_ptr<Obj> newObj = std::make_shared<Obj>(i);
    g_mutex.lock();
    g_obj = newObj;
    g_mutex.unlock();
  }
}

void read_proc() {
  constexpr int CNT = 1000000;
  for (int i = 0; i < CNT; i++) {
    g_mutex.lock();
    std::shared_ptr<Obj> obj = g_obj;
    g_mutex.unlock();
    if (obj != nullptr) obj->check();
  }
}

int main() {
  DLOG(INFO) << "beg main";

  constexpr int THREAD_CNT = 5;

  thread write_thread;
  thread read_thread[THREAD_CNT];

  write_thread = thread(write_proc);
  for (int i = 0; i < THREAD_CNT; i++) read_thread[i] = thread(read_proc);

  write_thread.join();
  for (int i = 0; i < THREAD_CNT; i++) read_thread[i].join();

  DLOG(INFO) << "end main";
  return 0;
}
