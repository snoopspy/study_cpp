#include <glog/logging.h>
#include <gtest/gtest.h>
#include "procinfo.h"

TEST(ProcfInfo, test)
{
  ProcInfo pi;

  pi.load(); uint64_t oldVM = pi.getVM(); uint64_t oldRSS = pi.getRSS();

  constexpr size_t SIZE = 1048576 * 10; // 10MBytes
  char* p = (char*)malloc(SIZE);
  for (size_t i = 0; i < SIZE; i++)
    p[i] = '\0';

  pi.load(); uint64_t newVM = pi.getVM(); uint64_t newRSS = pi.getRSS();

  DLOG(INFO) << "vm  : old=" << oldVM  << " new=" << newVM;
  DLOG(INFO) << "rss : old=" << oldRSS << " new=" << newRSS;

  u_int64_t diffRSS = newRSS - oldRSS;
  DLOG(INFO) << "diff rss=" << diffRSS << " SIZE/1024=" << SIZE / 1024;

  EXPECT_NEAR(newRSS - oldRSS,(u_int64_t)(SIZE) / 1024, 100);
}
