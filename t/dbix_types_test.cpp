
#include <sparrow/test_run.h>
#include <sparrow/tap_base.h>

#include <dbix/types.h>

using namespace sparrow;
using namespace dbix;
//using namespace dbix::types;

class types_test : public tap_base<types_test>
{
  void init();
  void text_test();
};

void
types_test::init()
{
  add(2,&types_test::text_test);
}

void
types_test::text_test()
{
  types::text& txt = is::text();
  ok(txt.id() == 0,"type default text id is 0");
  types::text copy(txt);
  ok(copy.id() == 1,"id of first text type copy is 1");
}

int main(int argc,char **argv)
{
  test_run t(new types_test);
  t.plan();
  t.run();
  return 0;
}


