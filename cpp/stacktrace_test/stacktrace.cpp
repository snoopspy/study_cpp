#include <thread>
#include <assert.h>
#include <cxxabi.h>
#include <dirent.h>
#include <execinfo.h>
#include <glog/logging.h>
#include <sys/syscall.h>
#include "stacktrace.h"

StackTrace::StackTrace()
{
  DLOG(INFO) << "StackTrace::StackTrace()";
  prev_handler_ = 0;
  setOutput(stdout);
  setMaxFrames(10);
  setSignal(SIGUSR1);
}

StackTrace::~StackTrace()
{
  DLOG(INFO) << "StackTrace::~StackTrace()";
  unsetSignal();
}

void StackTrace::setOutput(FILE* output)
{
  output_ = output;
}

void StackTrace::setMaxFrames(int maxFrames)
{
  maxFrames_ = maxFrames;
}

void StackTrace::setSignal(int signum)
{
  unsetSignal();
  prev_handler_ = signal(signum, sighandler);
  if (prev_handler_ == SIG_ERR) {
    LOG(FATAL) << "Calling signal(" << signum << ") return SIG_ERR " << strerror(errno);
    prev_handler_ = 0;
  }
  signum_ = signum;
}

void StackTrace::unsetSignal()
{
  if (prev_handler_ != 0) {
    __sighandler_t res = signal(signum_, prev_handler_);
    assert(res == sighandler);
    prev_handler_ = 0;
  }
}

void StackTrace::dump()
{
  DIR *dir;

  if ((dir = opendir ("/proc/self/task")) == NULL) {
    LOG(ERROR) << "opendir return NULL " << strerror(errno);
    return;
  }

  pid_t tgid = getpid();
  struct dirent *ent;
  while ((ent = readdir(dir)) != NULL) {
    std::string s = ent->d_name;
    if (s == "." || s == "..") continue;
    pid_t tid = std::stoi(s);
    //DLOG(INFO) << "writing call stack for tid=" << tid;
    long int res = syscall(SYS_tgkill, tgid, tid, signum_); // tgkill(tgid, tid, signum_);
    if (res != 0) {
      LOG(ERROR) << "Error in call kill " << strerror(errno);
    }
  }
  closedir(dir);
}

void StackTrace::printStacktrace()
{
  mutex_.lock();

  fprintf(output_, "******** stack trace ******** (%ld)\n", syscall(SYS_gettid));

  // storage array for stack trace address data
  void* addrlist[maxFrames_ + 1];

  // retrieve current stack addresses
  int addrlen = backtrace(addrlist, sizeof(addrlist) / sizeof(void*));

  if (addrlen == 0) {
    fprintf(output_, "  <empty, possibly corrupt>\n");
    mutex_.unlock();
    return;
  }

  // resolve addresses into strings containing "filename(function+address)",
  // this array must be free()-ed
  char** symbollist = backtrace_symbols(addrlist, addrlen);

  // allocate string which will be filled with the demangled function name
  size_t funcnamesize = 256;
  char* funcname = (char*)malloc(funcnamesize);

  // iterate over the returned symbol lines. skip the first, it is the
  // address of this function.
  for (int i = 1; i < addrlen; i++)
  {
    char *begin_name = 0, *begin_offset = 0, *end_offset = 0;

    // find parentheses and +address offset surrounding the mangled name:
    // ./module(function+0x15c) [0x8048a6d]
    for (char *p = symbollist[i]; *p; ++p)
    {
      if (*p == '(')
        begin_name = p;
      else if (*p == '+')
        begin_offset = p;
      else if (*p == ')' && begin_offset) {
        end_offset = p;
        break;
      }
    }

    if (begin_name && begin_offset && end_offset && begin_name < begin_offset)
    {
      *begin_name++ = '\0';
      *begin_offset++ = '\0';
      *end_offset = '\0';

      // mangled name is now in [begin_name, begin_offset) and caller
      // offset in [begin_offset, end_offset). now apply
      // __cxa_demangle():

      int status;
      char* ret = abi::__cxa_demangle(begin_name,
      funcname, &funcnamesize, &status);
      if (status == 0) {
        funcname = ret; // use possibly realloc()-ed string
        fprintf(output_, "  %s : %s+%s\n",
        symbollist[i], funcname, begin_offset);
      }
      else {
        // demangling failed. Output function name as a C function with
        // no arguments.
        fprintf(output_, "  %s : %s()+%s\n",
        symbollist[i], begin_name, begin_offset);
      }
    }
    else
    {
      // couldn't parse the line? print the whole line.
      fprintf(output_, "  %s\n", symbollist[i]);
    }
  }

  free(funcname);
  free(symbollist);

  mutex_.unlock();
}

void StackTrace::sighandler(int signum)
{
  if (signum == StackTrace::instance().signum_)
    StackTrace::instance().printStacktrace();
}

StackTrace& StackTrace::instance()
{
  static StackTrace _instance;
  return _instance;
}
