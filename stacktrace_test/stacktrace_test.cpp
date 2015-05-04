#include <thread>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include "stacktrace.h"

TEST(StackTrace, test)
{
  LOG(INFO) << "beg dump";
  StackTrace::instance().dump();
  LOG(INFO) << "aft dump";
}

void sleepProc(int n)
{
  LOG(INFO) << "beg sleepProc " << n;
  for (int i = 0; i < 5; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  LOG(INFO) << "end sleepProc " << n;
}

TEST(StackTrace, sleepThreadTest)
{
  LOG(INFO) << "beg sleepThreadTest";
  {
    constexpr int THREAD_CNT = 3;
    std::vector<std::thread> threads;
    for (int i = 0; i < THREAD_CNT; i++)
      threads.emplace_back(sleepProc, i);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    StackTrace::instance().dump();

    for (auto& thread: threads)
      thread.join();
  }
  LOG(INFO) << "end sleepThreadTest";
}

#include <atomic>
namespace SpinLockTest {
  std::atomic_flag lock_ = ATOMIC_FLAG_INIT;
  volatile bool active_ = false;

  void run() {
    while (active_) {
      while (lock_.test_and_set(std::memory_order_acquire)) // acquire lock
           ; // spin
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      lock_.clear(std::memory_order_release); // release lock
    }
  }
};

TEST(StackTrace, spinLockTest)
{
  LOG(INFO) << "beg spinLockTest";
  {
    SpinLockTest::active_ = true;
    static constexpr int THREAD_CNT = 3;
    std::vector<std::thread> threads;
    for (int n = 0; n < THREAD_CNT; ++n) {
      threads.emplace_back(SpinLockTest::run);
    }
    for (int i = 0; i < 10; i++) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      StackTrace::instance().dump();;
    }

    SpinLockTest::active_ = false;
    for (auto& thread : threads) {
        thread.join();
    }
  }
  LOG(INFO) << "end spinLockTest";
}
