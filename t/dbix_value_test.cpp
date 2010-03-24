
#include <sparrow/test_run.h>
#include <sparrow/tap_base.h>

#include <dbix/value.h>

using namespace sparrow;
using namespace dbix;

class value_test : public tap_base<value_test>
{
  void init();
  void double_test();
  void int_test();
  void string_test();
  void boolean_test();
};

void
value_test::init()
{
  add(2,&value_test::double_test);
  add(2,&value_test::int_test);
  add(2,&value_test::string_test);
  add(2,&value_test::boolean_test);
}

void
value_test::double_test()
{
  value v(2.0);
  ok(v.to_double() == 2.0,"to_double is ok");
  v.to_double() += 2.0;
  ok(v.to_double() == 4.0,"modifying via reference is ok");
}

void
value_test::int_test()
{
  value v(2);
  ok(v.to_int() == 2,"to_int is ok");
  v.to_int() += 2;
  ok(v.to_int() == 4,"modifying int via reference is ok");
}

void
value_test::string_test()
{
  value v("123");
  ok(v.to_string() == "123","string is ok");
  v.to_string() += "abc";
  ok(v.to_string() == "123abc","modifying string via reference is ok");
}

void
value_test::boolean_test()
{
  value v(true);
  ok(v.to_bool(),"a true value");
  v.to_bool() = false;
  ok(!v.to_bool(),"boolean value modyfied");
}

int main(int argc, char** argv)
{
  test_run t(new value_test);
  t.plan();
  t.run();
  return 0;
}

