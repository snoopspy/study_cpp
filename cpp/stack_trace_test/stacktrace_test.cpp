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

void sleepThreadProc(int no)
{
  LOG(INFO) << "beg sleepThreadProc " << no;
  for (int i = 0; i < 5; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  LOG(INFO) << "end sleepThreadProc " << no;
}

TEST(StackTrace, sleepThreadTest)
{
  LOG(INFO) << "beg sleepThreadTest";
  {
    constexpr int THREAD_CNT = 3;
    std::thread threads[THREAD_CNT];
    for (int i = 0; i < THREAD_CNT; i++)
      threads[i] = std::thread(sleepThreadProc, i);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    StackTrace::instance().dump();

    for (int i = 0; i < THREAD_CNT; i++)
      threads[i].join();
  }
  LOG(INFO) << "beg sleepThreadTest";
}
