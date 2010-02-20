
#ifndef _SPARROW_TAP_SUITE_
#define _SPARROW_TAP_SUITE_


#include <string>
#include <iostream>

namespace sparrow {

class tap_suite
{
public:
  virtual ~tap_suite();
  virtual void init() = 0;
  virtual int test_count() = 0;
  virtual void test_run() = 0;
  void ok(bool, const std::string& = "");
};

}

#endif
