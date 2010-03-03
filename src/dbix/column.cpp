

#include <dbix/column.h>

using namespace std;
using namespace dbix;
using namespace dbix::types;

column::column(string n)
  : name_(n)
  , withnull(false)
  , typeptr(NULL)
{}

column::column(string n,const type& t)
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



