#pragma once

#include <cstdint>
#include <string>

class ProcInfo {
public:
  ProcInfo& load(pid_t pid = 0);
  uint64_t getVM();
  uint64_t getRSS();

public:
  uint64_t pid;
  std::string comm;
  std::string state;
  uint64_t ppid;
  uint64_t pgrp;
  uint64_t session;
  uint64_t tty_nr;
  uint64_t tpgid;
  uint64_t flags;
  uint64_t minflt;
  uint64_t cminflt;
  uint64_t majflt;
  uint64_t cmajflt;
  uint64_t utime;
  uint64_t stime;
  uint64_t cutime;
  uint64_t cstime;
  uint64_t priority;
  uint64_t nice;
  uint64_t O;
  uint64_t itrealvalue;
  uint64_t starttime;
  uint64_t vsize;
  uint64_t rss;
};
