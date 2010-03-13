
#include <dbix/types/integer.h>

using namespace dbix::types;

integer::integer()
  : type()
{

}

integer::integer(const integer& o)
{
  identity = new_id();
}

integer::~integer()
{

}

int
integer::new_id()
{
  static int id = 0;
  return ++id;
}

