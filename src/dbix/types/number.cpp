
#include <dbix/types/number.h>

using namespace dbix::types;

number::number()
  : type()
{

}

number::number(const number& o)
{
  identity = new_id();
}

number::~number()
{

}

int
number::new_id()
{
  static int id = 0;
  return ++id;
}

