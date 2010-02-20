

#ifndef _SPARROW_TEST_RUN_
#define _SPARROW_TEST_RUN_

#include <sparrow/tap_suite.h>

namespace sparrow {

class test_run
{
public:
  test_run(tap_suite*);
  ~test_run();
  void plan();
  int run();
private:
  tap_suite* suite;
};

}

#endif

