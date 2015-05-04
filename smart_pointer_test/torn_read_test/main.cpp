#include <thread>
#include <glog/logging.h>

using namespace std;

volatile uint64_t g_value;

void write_proc() {
  constexpr int CNT = 1000000;
  for (uint32_t i = 0; i < CNT; i++) {
    uint32_t upper = i;
    uint32_t lower = upper;
    uint64_t v = ((uint64_t)upper << 32) | lower;
    g_value = v;
  }
}

void read_proc() {
  constexpr int CNT = 1000000;
  for (int i = 0; i < CNT; i++) {
    uint64_t v = g_value;
    uint32_t upper = v >> 32;
    uint32_t lower = v;
    if (upper != lower) {
      LOG(ERROR) << "oops!!!" << hex << upper << ' ' << hex << lower;
    }
  }
}

int main() {
  constexpr int THREAD_CNT = 5;

  DLOG(INFO) << "beg main";

  thread write_thread;
  thread read_thread[THREAD_CNT];

  write_thread = thread(write_proc);
  for (int i = 0; i < THREAD_CNT; i++) read_thread[i] = thread(read_proc);

  write_thread.join();
  for (int i = 0; i < THREAD_CNT; i++) read_thread[i].join();

  DLOG(INFO) << "end main";
  return 0;
}
