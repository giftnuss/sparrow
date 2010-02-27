
#include <dbix/types/text.h>

using namespace dbix::types;

text::text()
  : type()
{

}

text::text(const text& o)
{
  identity = new_id();
}

text::~text()
{

}

int
text::new_id()
{
  static int id = 0;
  return ++id;
}

