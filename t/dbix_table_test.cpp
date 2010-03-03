
#include <sparrow/test_run.h>
#include <sparrow/tap_base.h>

#include <dbix/table.h>
#include <dbix/types.h>

using namespace sparrow;
using namespace dbix;

class table_test : public tap_base<table_test>
{
  void init();
  void all_types_test();
};

void
table_test::init()
{
  add(2,&table_test::all_types_test);
}

void
table_test::all_types_test()
{
  table t("alltypes");
  ok(t.name() == "alltypes","naming a table works");
  t.has(*(new column("string",is::text())));
  ok(t.get_column("string").name() == "string","column name works as expected");
}

int main(int argc, char** argv)
{
  test_run t(new table_test);
  t.plan();
  t.run();
  return 0;
}

