#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include "procinfo.h"

ProcInfo& ProcInfo::load(pid_t pid)
{
  std::string pid_str = pid == 0 ? "self" : std::to_string(pid);
  std::string file_name = "/proc/" + pid_str + "/stat";

  std::ifstream stat_stream(file_name.c_str(), std::ios_base::in);

  stat_stream >> pid;
  stat_stream >> comm;
  stat_stream >> state;
  stat_stream >> ppid;
  stat_stream >> pgrp;
  stat_stream >> session;
  stat_stream >> tty_nr;
  stat_stream >> tpgid;
  stat_stream >> flags;
  stat_stream >> minflt;
  stat_stream >> cminflt;
  stat_stream >> majflt;
  stat_stream >> cmajflt;
  stat_stream >> utime;
  stat_stream >> stime;
  stat_stream >> cutime;
  stat_stream >> cstime;
  stat_stream >> priority;
  stat_stream >> nice;
  stat_stream >> O;
  stat_stream >> itrealvalue;
  stat_stream >> starttime;
  stat_stream >> vsize;
  stat_stream >> rss;

  stat_stream.close();

  return *this;
}

uint64_t ProcInfo::getVM()
{
  return vsize / 1024;
}

uint64_t ProcInfo::getRSS()
{
  long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
  return rss * page_size_kb;
}
