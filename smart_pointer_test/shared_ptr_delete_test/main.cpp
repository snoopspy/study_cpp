#include <memory>
#include <glog/logging.h>

class Obj {
protected:
  int n_;
public:
  Obj(int n) : n_(n)  { DLOG(INFO) << "Obj::Obj  " << n_; }
  ~Obj() { DLOG(INFO) << "Obj::~Obj " << n_; }
};

void deleteObj(Obj* obj) {
  DLOG(INFO) << "deleteObj " << (void*)obj;
  delete obj;
}

int main() {
  DLOG(INFO) << "beg main";
  {
    std::shared_ptr<Obj> objPtr = std::shared_ptr<Obj>(new Obj(0), deleteObj);
  }
  DLOG(INFO) << "end main";
}
