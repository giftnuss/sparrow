
#include <dbix/types/boolean.h>

using namespace dbix::types;

boolean::boolean()
  : type()
{

}

boolean::boolean(const boolean& o)
{
  identity = new_id();
}

boolean::~boolean()
{

}

int
boolean::new_id()
{
  static int id = 0;
  return ++id;
}

void
boolean::valid_value(const std::string& s, dbix::value* v)
{
  bool b = true;
  if(s.size() == 0) {
    b = false;
  }
  if(v) v->is(b);
}

