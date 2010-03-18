

#include <dbix/column.h>

using namespace std;
using namespace dbix;

column::column(string n)
  : name_(n)
  , withnull(false)
  , typeptr(NULL)
{}

column::column(string n,const types::type& t)
  : name_(n)
  , withnull(false)
  , typeptr(&t)
{}

const string&
column::name() const
{
  return name_;
}

column::~column()
{}

column&
column::nullable(bool b)
{
  withnull = b;
  return *this;
}

bool
column::is_nullable() const
{
  return withnull;
}

const types::type*
column::type()
{
  return typeptr;
}

assignment&
column::assign_to(dbix::record*r)
{
  static assignment* a = new assignment;
  a->set_record(r);

  return *a;
}
