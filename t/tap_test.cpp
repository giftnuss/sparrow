
/**
 * Basic usage example
 */
#include <sparrow/test_run.h>
#include <sparrow/tap_base.h>

using namespace sparrow;
 
class tap_test : public tap_base<tap_test>
{
  void init();
  void oktest(){ ok(true,"this is true"); };
};

void
tap_test::init()
{
  add(1,&tap_test::oktest);
}


int main(int argc, char** argv)
{
  test_run t(new tap_test);
  t.plan();
  t.run();
  return 0;
}

