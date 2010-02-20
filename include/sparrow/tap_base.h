
#ifndef _SPARROW_TAP_BASE_
#define _SPARROW_TAP_BASE_

#include <vector>
#include <sparrow/tap_suite.h>

namespace sparrow {

using namespace std;

template<typename T>
class tap_base : public tap_suite
{
  public:
  void add(int,void (T::*)());
  int test_count();
  void test_run();

  private:
  vector<int> count;
  vector<void (T::*)()> fp;
};

template<typename T>
void tap_base<T>::add(int cnt, void (T::*f)())
{
  count.push_back(cnt);
  fp.push_back(f);
}

template<typename T>
int tap_base<T>::test_count()
{
  int sum = 0;
  vector<int>::iterator it;
  for(it = count.begin(); it != count.end(); ++it) {
    sum += *it;
  }
  return sum;
}

template<typename T>
void tap_base<T>::test_run()
{
  // can not use this, it is an upcast?
  T* self = new T();
  // self->fp = this->fp;
  // cout << self->fp.size() << this->fp.size() << endl;
  void (T::*f)();
  for(unsigned int i=0; i < fp.size(); ++i) {
    f = fp[i];
    (self->*f)();
  }
  delete self;
}

} // end namespace sparrow

#endif

